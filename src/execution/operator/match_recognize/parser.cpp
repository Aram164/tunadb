#include "parser.hpp"
#include <iostream>

Node::Node(NodeType type, char value) 
    : type(type), value(value), left(nullptr), right(nullptr) {}

Node::~Node() { 
    delete left; 
    delete right; 
}

Parser::Parser(Lexer &lexer) 
    : lexer(lexer), has_lookahead(false) {}

static std::string TokenToString(TokenType type) {
    switch (type) {
    case TokenType::VAR:
        return "variable";
    case TokenType::LPAREN:
        return "'('";
    case TokenType::RPAREN:
        return "')'";
    case TokenType::LBRACE:
        return "'{'";
    case TokenType::RBRACE:
        return "'}'";
    case TokenType::STAR:
        return "'*'";
    case TokenType::PLUS:
        return "'+'";
    case TokenType::OPTIONAL:
        return "'?'";
    case TokenType::OR:
        return "'|'";
    case TokenType::END:
        return "end of pattern";
    default:
        return "token";
    }
}

Token Parser::peek() {
    if(!has_lookahead) {
        lookahead = lexer.next_token();
        has_lookahead = true;
    }
    return lookahead;
}

Token Parser::consume() {
    Token t;
    if(has_lookahead) {
        t = lookahead;
        has_lookahead = false;
    } else {
        t = lexer.next_token();
    }
    return t;
}

bool is_quantifier(TokenType t) {
    return t == TokenType::STAR || t == TokenType::PLUS || t == TokenType::OPTIONAL;
}

bool is_quantifier(NodeType type) {
    return type == NodeType::STAR || type == NodeType::PLUS || type == NodeType::OPTIONAL;
}

Node* Parser::parse() {
    Node* root = parse_pattern();
    Token trailing = peek();
    if (trailing.type != TokenType::END) {
        delete root;
        throw std::runtime_error("Unexpected trailing token " + TokenToString(trailing.type));
    }
    return root;
}

/* 
Grammatik:
    row_pattern_nonempty ::= row_branch ('|' row_branch)*
    row_branch           ::= row_piece+
    row_piece            ::= row_atom row_quantifier?
    row_atom             ::= VAR | '(' row_pattern_nonempty ')'
    row_quantifier       ::= '*' | '+' | '?'
*/

// row_pattern_nonempty ::= row_branch ('|' row_branch)*
Node* Parser::parse_pattern() {
    Node* left = parse_branch();

    while(peek().type == TokenType::OR) {
        consume();
        Node* right = parse_branch();
        Node* parent = new Node(NodeType::ALT);
        parent->left = left;
        parent->right = right;
        left = parent;
    }

    return left;
}

// row_branch ::= row_piece+
Node* Parser::parse_branch() {
    Node* left = parse_piece();

    while(true) {
        Token t = peek();

        if(t.type == TokenType::VAR || t.type == TokenType::LPAREN) {
            Node* right = parse_piece();
            Node* parent = new Node(NodeType::CONCAT);
            parent->left = left;
            parent->right = right;
            left = parent;
        } else break;
    }

    return left;
}

// row_piece ::= row_atom row_quantifier?
// row_quantifier ::= '*' | '+' | '?'
Node* Parser::parse_piece() {
    Node* node = parse_atom();
    Token t = peek();

    if(t.type == TokenType::LBRACE || t.type == TokenType::RBRACE) { 
        throw std::runtime_error("Quantifier syntax {m,n} is not supported");
    }
    
    if(is_quantifier(t.type)) {
        consume();

        Node* parent = new Node(
            t.type == TokenType::STAR  ? NodeType::STAR :
            t.type == TokenType::PLUS  ? NodeType::PLUS :
                                         NodeType::OPTIONAL
        );
        parent->left = node;
        node = parent;

        Token next = peek();
        if (next.type == TokenType::OPTIONAL) {
            throw std::runtime_error("Reluctant quantifiers are not supported");
        }
        if (next.type == TokenType::STAR || next.type == TokenType::PLUS) {
            throw std::runtime_error("Multiple quantifiers on one pattern atom are not supported");
        }
        if (next.type == TokenType::LBRACE || next.type == TokenType::RBRACE) {
            throw std::runtime_error("Quantifier syntax {m,n} is not supported");
        }
    }

    return node;
}

// row_atom ::= VAR | '(' row_pattern_nonempty ')'
Node* Parser::parse_atom() {
    Token t = peek();
    t = consume();

    if(t.type == TokenType::VAR) {
        return new Node(NodeType::VAR, t.value);
    } else if(t.type == TokenType::LPAREN) {
        Node* node = parse_pattern();
        Token t2 = consume();
        if(t2.type != TokenType::RPAREN) {
            throw std::runtime_error("Expected ')'");
        }
        return node;
    } else {
        throw std::runtime_error("Unexpected token " + TokenToString(t.type) + " in PATTERN");
    }
}
