/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_BASE_YY_THIRD_PARTY_LIBPG_QUERY_GRAMMAR_GRAMMAR_OUT_HPP_INCLUDED
# define YY_BASE_YY_THIRD_PARTY_LIBPG_QUERY_GRAMMAR_GRAMMAR_OUT_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int base_yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENT = 258,                   /* IDENT  */
    FCONST = 259,                  /* FCONST  */
    SCONST = 260,                  /* SCONST  */
    BCONST = 261,                  /* BCONST  */
    XCONST = 262,                  /* XCONST  */
    Op = 263,                      /* Op  */
    ICONST = 264,                  /* ICONST  */
    PARAM = 265,                   /* PARAM  */
    TYPECAST = 266,                /* TYPECAST  */
    DOT_DOT = 267,                 /* DOT_DOT  */
    COLON_EQUALS = 268,            /* COLON_EQUALS  */
    EQUALS_GREATER = 269,          /* EQUALS_GREATER  */
    INTEGER_DIVISION = 270,        /* INTEGER_DIVISION  */
    POWER_OF = 271,                /* POWER_OF  */
    SINGLE_ARROW = 272,            /* SINGLE_ARROW  */
    DOUBLE_ARROW = 273,            /* DOUBLE_ARROW  */
    SINGLE_COLON = 274,            /* SINGLE_COLON  */
    LESS_EQUALS = 275,             /* LESS_EQUALS  */
    GREATER_EQUALS = 276,          /* GREATER_EQUALS  */
    NOT_EQUALS = 277,              /* NOT_EQUALS  */
    ABORT_P = 278,                 /* ABORT_P  */
    ABSOLUTE_P = 279,              /* ABSOLUTE_P  */
    ACCESS = 280,                  /* ACCESS  */
    ACTION = 281,                  /* ACTION  */
    ADD_P = 282,                   /* ADD_P  */
    ADMIN = 283,                   /* ADMIN  */
    AFTER = 284,                   /* AFTER  */
    AGGREGATE = 285,               /* AGGREGATE  */
    ALL = 286,                     /* ALL  */
    ALSO = 287,                    /* ALSO  */
    ALTER = 288,                   /* ALTER  */
    ALWAYS = 289,                  /* ALWAYS  */
    ANALYSE = 290,                 /* ANALYSE  */
    ANALYZE = 291,                 /* ANALYZE  */
    AND = 292,                     /* AND  */
    ANTI = 293,                    /* ANTI  */
    ANY = 294,                     /* ANY  */
    ARRAY = 295,                   /* ARRAY  */
    AS = 296,                      /* AS  */
    ASC_P = 297,                   /* ASC_P  */
    ASOF = 298,                    /* ASOF  */
    ASSERTION = 299,               /* ASSERTION  */
    ASSIGNMENT = 300,              /* ASSIGNMENT  */
    ASYMMETRIC = 301,              /* ASYMMETRIC  */
    AT = 302,                      /* AT  */
    ATTACH = 303,                  /* ATTACH  */
    ATTRIBUTE = 304,               /* ATTRIBUTE  */
    AUTHORIZATION = 305,           /* AUTHORIZATION  */
    BACKWARD = 306,                /* BACKWARD  */
    BEFORE = 307,                  /* BEFORE  */
    BEGIN_P = 308,                 /* BEGIN_P  */
    BETWEEN = 309,                 /* BETWEEN  */
    BIGINT = 310,                  /* BIGINT  */
    BINARY = 311,                  /* BINARY  */
    BIT = 312,                     /* BIT  */
    BOOLEAN_P = 313,               /* BOOLEAN_P  */
    BOTH = 314,                    /* BOTH  */
    BY = 315,                      /* BY  */
    CACHE = 316,                   /* CACHE  */
    CALL_P = 317,                  /* CALL_P  */
    CALLED = 318,                  /* CALLED  */
    CASCADE = 319,                 /* CASCADE  */
    CASCADED = 320,                /* CASCADED  */
    CASE = 321,                    /* CASE  */
    CAST = 322,                    /* CAST  */
    CATALOG_P = 323,               /* CATALOG_P  */
    CENTURIES_P = 324,             /* CENTURIES_P  */
    CENTURY_P = 325,               /* CENTURY_P  */
    CHAIN = 326,                   /* CHAIN  */
    CHAR_P = 327,                  /* CHAR_P  */
    CHARACTER = 328,               /* CHARACTER  */
    CHARACTERISTICS = 329,         /* CHARACTERISTICS  */
    CHECK_P = 330,                 /* CHECK_P  */
    CHECKPOINT = 331,              /* CHECKPOINT  */
    CLASS = 332,                   /* CLASS  */
    CLOSE = 333,                   /* CLOSE  */
    CLUSTER = 334,                 /* CLUSTER  */
    COALESCE = 335,                /* COALESCE  */
    COLLATE = 336,                 /* COLLATE  */
    COLLATION = 337,               /* COLLATION  */
    COLUMN = 338,                  /* COLUMN  */
    COLUMNS = 339,                 /* COLUMNS  */
    COMMENT = 340,                 /* COMMENT  */
    COMMENTS = 341,                /* COMMENTS  */
    COMMIT = 342,                  /* COMMIT  */
    COMMITTED = 343,               /* COMMITTED  */
    COMPRESSION = 344,             /* COMPRESSION  */
    CONCURRENTLY = 345,            /* CONCURRENTLY  */
    CONFIGURATION = 346,           /* CONFIGURATION  */
    CONFLICT = 347,                /* CONFLICT  */
    CONNECTION = 348,              /* CONNECTION  */
    CONSTRAINT = 349,              /* CONSTRAINT  */
    CONSTRAINTS = 350,             /* CONSTRAINTS  */
    CONTENT_P = 351,               /* CONTENT_P  */
    CONTINUE_P = 352,              /* CONTINUE_P  */
    CONVERSION_P = 353,            /* CONVERSION_P  */
    COPY = 354,                    /* COPY  */
    COST = 355,                    /* COST  */
    CREATE_P = 356,                /* CREATE_P  */
    CROSS = 357,                   /* CROSS  */
    CSV = 358,                     /* CSV  */
    CUBE = 359,                    /* CUBE  */
    CURRENT_P = 360,               /* CURRENT_P  */
    CURSOR = 361,                  /* CURSOR  */
    CYCLE = 362,                   /* CYCLE  */
    DATA_P = 363,                  /* DATA_P  */
    DATABASE = 364,                /* DATABASE  */
    DAY_P = 365,                   /* DAY_P  */
    DAYS_P = 366,                  /* DAYS_P  */
    DEALLOCATE = 367,              /* DEALLOCATE  */
    DEC = 368,                     /* DEC  */
    DECADE_P = 369,                /* DECADE_P  */
    DECADES_P = 370,               /* DECADES_P  */
    DECIMAL_P = 371,               /* DECIMAL_P  */
    DECLARE = 372,                 /* DECLARE  */
    DEFAULT = 373,                 /* DEFAULT  */
    DEFAULTS = 374,                /* DEFAULTS  */
    DEFERRABLE = 375,              /* DEFERRABLE  */
    DEFERRED = 376,                /* DEFERRED  */
    DEFINE = 377,                  /* DEFINE  */
    DEFINER = 378,                 /* DEFINER  */
    DELETE_P = 379,                /* DELETE_P  */
    DELIMITER = 380,               /* DELIMITER  */
    DELIMITERS = 381,              /* DELIMITERS  */
    DEPENDS = 382,                 /* DEPENDS  */
    DESC_P = 383,                  /* DESC_P  */
    DESCRIBE = 384,                /* DESCRIBE  */
    DETACH = 385,                  /* DETACH  */
    DICTIONARY = 386,              /* DICTIONARY  */
    DISABLE_P = 387,               /* DISABLE_P  */
    DISCARD = 388,                 /* DISCARD  */
    DISTINCT = 389,                /* DISTINCT  */
    DO = 390,                      /* DO  */
    DOCUMENT_P = 391,              /* DOCUMENT_P  */
    DOMAIN_P = 392,                /* DOMAIN_P  */
    DOUBLE_P = 393,                /* DOUBLE_P  */
    DROP = 394,                    /* DROP  */
    EACH = 395,                    /* EACH  */
    ELSE = 396,                    /* ELSE  */
    ENABLE_P = 397,                /* ENABLE_P  */
    ENCODING = 398,                /* ENCODING  */
    ENCRYPTED = 399,               /* ENCRYPTED  */
    END_P = 400,                   /* END_P  */
    ENUM_P = 401,                  /* ENUM_P  */
    ERROR_P = 402,                 /* ERROR_P  */
    ESCAPE = 403,                  /* ESCAPE  */
    EVENT = 404,                   /* EVENT  */
    EXCEPT = 405,                  /* EXCEPT  */
    EXCLUDE = 406,                 /* EXCLUDE  */
    EXCLUDING = 407,               /* EXCLUDING  */
    EXCLUSIVE = 408,               /* EXCLUSIVE  */
    EXECUTE = 409,                 /* EXECUTE  */
    EXISTS = 410,                  /* EXISTS  */
    EXPLAIN = 411,                 /* EXPLAIN  */
    EXPORT_P = 412,                /* EXPORT_P  */
    EXPORT_STATE = 413,            /* EXPORT_STATE  */
    EXTENSION = 414,               /* EXTENSION  */
    EXTENSIONS = 415,              /* EXTENSIONS  */
    EXTERNAL = 416,                /* EXTERNAL  */
    EXTRACT = 417,                 /* EXTRACT  */
    FALSE_P = 418,                 /* FALSE_P  */
    FAMILY = 419,                  /* FAMILY  */
    FETCH = 420,                   /* FETCH  */
    FILTER = 421,                  /* FILTER  */
    FIRST_P = 422,                 /* FIRST_P  */
    FLOAT_P = 423,                 /* FLOAT_P  */
    FOLLOWING = 424,               /* FOLLOWING  */
    FOR = 425,                     /* FOR  */
    FORCE = 426,                   /* FORCE  */
    FOREIGN = 427,                 /* FOREIGN  */
    FORWARD = 428,                 /* FORWARD  */
    FREEZE = 429,                  /* FREEZE  */
    FROM = 430,                    /* FROM  */
    FULL = 431,                    /* FULL  */
    FUNCTION = 432,                /* FUNCTION  */
    FUNCTIONS = 433,               /* FUNCTIONS  */
    GENERATED = 434,               /* GENERATED  */
    GLOB = 435,                    /* GLOB  */
    GLOBAL = 436,                  /* GLOBAL  */
    GRANT = 437,                   /* GRANT  */
    GRANTED = 438,                 /* GRANTED  */
    GROUP_P = 439,                 /* GROUP_P  */
    GROUPING = 440,                /* GROUPING  */
    GROUPING_ID = 441,             /* GROUPING_ID  */
    GROUPS = 442,                  /* GROUPS  */
    HANDLER = 443,                 /* HANDLER  */
    HAVING = 444,                  /* HAVING  */
    HEADER_P = 445,                /* HEADER_P  */
    HELLO = 446,                   /* HELLO  */
    HOLD = 447,                    /* HOLD  */
    HOUR_P = 448,                  /* HOUR_P  */
    HOURS_P = 449,                 /* HOURS_P  */
    IDENTITY_P = 450,              /* IDENTITY_P  */
    IF_P = 451,                    /* IF_P  */
    IGNORE_P = 452,                /* IGNORE_P  */
    ILIKE = 453,                   /* ILIKE  */
    IMMEDIATE = 454,               /* IMMEDIATE  */
    IMMUTABLE = 455,               /* IMMUTABLE  */
    IMPLICIT_P = 456,              /* IMPLICIT_P  */
    IMPORT_P = 457,                /* IMPORT_P  */
    IN_P = 458,                    /* IN_P  */
    INCLUDE_P = 459,               /* INCLUDE_P  */
    INCLUDING = 460,               /* INCLUDING  */
    INCREMENT = 461,               /* INCREMENT  */
    INDEX = 462,                   /* INDEX  */
    INDEXES = 463,                 /* INDEXES  */
    INHERIT = 464,                 /* INHERIT  */
    INHERITS = 465,                /* INHERITS  */
    INITIALLY = 466,               /* INITIALLY  */
    INLINE_P = 467,                /* INLINE_P  */
    INNER_P = 468,                 /* INNER_P  */
    INOUT = 469,                   /* INOUT  */
    INPUT_P = 470,                 /* INPUT_P  */
    INSENSITIVE = 471,             /* INSENSITIVE  */
    INSERT = 472,                  /* INSERT  */
    INSTALL = 473,                 /* INSTALL  */
    INSTEAD = 474,                 /* INSTEAD  */
    INT_P = 475,                   /* INT_P  */
    INTEGER = 476,                 /* INTEGER  */
    INTERSECT = 477,               /* INTERSECT  */
    INTERVAL = 478,                /* INTERVAL  */
    INTO = 479,                    /* INTO  */
    INVOKER = 480,                 /* INVOKER  */
    IS = 481,                      /* IS  */
    ISNULL = 482,                  /* ISNULL  */
    ISOLATION = 483,               /* ISOLATION  */
    JOIN = 484,                    /* JOIN  */
    JSON = 485,                    /* JSON  */
    KEY = 486,                     /* KEY  */
    LABEL = 487,                   /* LABEL  */
    LAMBDA = 488,                  /* LAMBDA  */
    LANGUAGE = 489,                /* LANGUAGE  */
    LARGE_P = 490,                 /* LARGE_P  */
    LAST_P = 491,                  /* LAST_P  */
    LATERAL_P = 492,               /* LATERAL_P  */
    LEADING = 493,                 /* LEADING  */
    LEAKPROOF = 494,               /* LEAKPROOF  */
    LEFT = 495,                    /* LEFT  */
    LEVEL = 496,                   /* LEVEL  */
    LIKE = 497,                    /* LIKE  */
    LIMIT = 498,                   /* LIMIT  */
    LISTEN = 499,                  /* LISTEN  */
    LOAD = 500,                    /* LOAD  */
    LOCAL = 501,                   /* LOCAL  */
    LOCATION = 502,                /* LOCATION  */
    LOCK_P = 503,                  /* LOCK_P  */
    LOCKED = 504,                  /* LOCKED  */
    LOGGED = 505,                  /* LOGGED  */
    MACRO = 506,                   /* MACRO  */
    MAP = 507,                     /* MAP  */
    MAPPING = 508,                 /* MAPPING  */
    MATCH = 509,                   /* MATCH  */
    MATCH_RECOGNIZE = 510,         /* MATCH_RECOGNIZE  */
    MATCHED = 511,                 /* MATCHED  */
    MATERIALIZED = 512,            /* MATERIALIZED  */
    MAXVALUE = 513,                /* MAXVALUE  */
    MEASURES = 514,                /* MEASURES  */
    MERGE = 515,                   /* MERGE  */
    METHOD = 516,                  /* METHOD  */
    MICROSECOND_P = 517,           /* MICROSECOND_P  */
    MICROSECONDS_P = 518,          /* MICROSECONDS_P  */
    MILLENNIA_P = 519,             /* MILLENNIA_P  */
    MILLENNIUM_P = 520,            /* MILLENNIUM_P  */
    MILLISECOND_P = 521,           /* MILLISECOND_P  */
    MILLISECONDS_P = 522,          /* MILLISECONDS_P  */
    MINUTE_P = 523,                /* MINUTE_P  */
    MINUTES_P = 524,               /* MINUTES_P  */
    MINVALUE = 525,                /* MINVALUE  */
    MODE = 526,                    /* MODE  */
    MONTH_P = 527,                 /* MONTH_P  */
    MONTHS_P = 528,                /* MONTHS_P  */
    MOVE = 529,                    /* MOVE  */
    NAME_P = 530,                  /* NAME_P  */
    NAMES = 531,                   /* NAMES  */
    NATIONAL = 532,                /* NATIONAL  */
    NATURAL = 533,                 /* NATURAL  */
    NCHAR = 534,                   /* NCHAR  */
    NEW = 535,                     /* NEW  */
    NEXT = 536,                    /* NEXT  */
    NO = 537,                      /* NO  */
    NONE = 538,                    /* NONE  */
    NOT = 539,                     /* NOT  */
    NOTHING = 540,                 /* NOTHING  */
    NOTIFY = 541,                  /* NOTIFY  */
    NOTNULL = 542,                 /* NOTNULL  */
    NOWAIT = 543,                  /* NOWAIT  */
    NULL_P = 544,                  /* NULL_P  */
    NULLIF = 545,                  /* NULLIF  */
    NULLS_P = 546,                 /* NULLS_P  */
    NUMERIC = 547,                 /* NUMERIC  */
    OBJECT_P = 548,                /* OBJECT_P  */
    OF = 549,                      /* OF  */
    OFF = 550,                     /* OFF  */
    OFFSET = 551,                  /* OFFSET  */
    OIDS = 552,                    /* OIDS  */
    OLD = 553,                     /* OLD  */
    ON = 554,                      /* ON  */
    ONE = 555,                     /* ONE  */
    ONLY = 556,                    /* ONLY  */
    OPERATOR = 557,                /* OPERATOR  */
    OPTION = 558,                  /* OPTION  */
    OPTIONS = 559,                 /* OPTIONS  */
    OR = 560,                      /* OR  */
    ORDER = 561,                   /* ORDER  */
    ORDINALITY = 562,              /* ORDINALITY  */
    OTHERS = 563,                  /* OTHERS  */
    OUT_P = 564,                   /* OUT_P  */
    OUTER_P = 565,                 /* OUTER_P  */
    OVER = 566,                    /* OVER  */
    OVERLAPS = 567,                /* OVERLAPS  */
    OVERLAY = 568,                 /* OVERLAY  */
    OVERRIDING = 569,              /* OVERRIDING  */
    OWNED = 570,                   /* OWNED  */
    OWNER = 571,                   /* OWNER  */
    PARALLEL = 572,                /* PARALLEL  */
    PARSER = 573,                  /* PARSER  */
    PARTIAL = 574,                 /* PARTIAL  */
    PARTITION = 575,               /* PARTITION  */
    PARTITIONED = 576,             /* PARTITIONED  */
    PASSING = 577,                 /* PASSING  */
    PASSWORD = 578,                /* PASSWORD  */
    PAST = 579,                    /* PAST  */
    PATTERN = 580,                 /* PATTERN  */
    PER = 581,                     /* PER  */
    PERCENT = 582,                 /* PERCENT  */
    PERSISTENT = 583,              /* PERSISTENT  */
    PIVOT = 584,                   /* PIVOT  */
    PIVOT_LONGER = 585,            /* PIVOT_LONGER  */
    PIVOT_WIDER = 586,             /* PIVOT_WIDER  */
    PLACING = 587,                 /* PLACING  */
    PLANS = 588,                   /* PLANS  */
    POLICY = 589,                  /* POLICY  */
    POSITION = 590,                /* POSITION  */
    POSITIONAL = 591,              /* POSITIONAL  */
    PRAGMA_P = 592,                /* PRAGMA_P  */
    PRECEDING = 593,               /* PRECEDING  */
    PRECISION = 594,               /* PRECISION  */
    PREPARE = 595,                 /* PREPARE  */
    PREPARED = 596,                /* PREPARED  */
    PRESERVE = 597,                /* PRESERVE  */
    PRIMARY = 598,                 /* PRIMARY  */
    PRIOR = 599,                   /* PRIOR  */
    PRIVILEGES = 600,              /* PRIVILEGES  */
    PROCEDURAL = 601,              /* PROCEDURAL  */
    PROCEDURE = 602,               /* PROCEDURE  */
    PROGRAM = 603,                 /* PROGRAM  */
    PUBLICATION = 604,             /* PUBLICATION  */
    QUALIFY = 605,                 /* QUALIFY  */
    QUARTER_P = 606,               /* QUARTER_P  */
    QUARTERS_P = 607,              /* QUARTERS_P  */
    QUOTE = 608,                   /* QUOTE  */
    RANGE = 609,                   /* RANGE  */
    READ_P = 610,                  /* READ_P  */
    REAL = 611,                    /* REAL  */
    REASSIGN = 612,                /* REASSIGN  */
    RECHECK = 613,                 /* RECHECK  */
    RECURSIVE = 614,               /* RECURSIVE  */
    REF = 615,                     /* REF  */
    REFERENCES = 616,              /* REFERENCES  */
    REFERENCING = 617,             /* REFERENCING  */
    REFRESH = 618,                 /* REFRESH  */
    REINDEX = 619,                 /* REINDEX  */
    RELATIVE_P = 620,              /* RELATIVE_P  */
    RELEASE = 621,                 /* RELEASE  */
    RENAME = 622,                  /* RENAME  */
    REPEATABLE = 623,              /* REPEATABLE  */
    REPLACE = 624,                 /* REPLACE  */
    REPLICA = 625,                 /* REPLICA  */
    RESET = 626,                   /* RESET  */
    RESPECT_P = 627,               /* RESPECT_P  */
    RESTART = 628,                 /* RESTART  */
    RESTRICT = 629,                /* RESTRICT  */
    RETURNING = 630,               /* RETURNING  */
    RETURNS = 631,                 /* RETURNS  */
    REVOKE = 632,                  /* REVOKE  */
    RIGHT = 633,                   /* RIGHT  */
    ROLE = 634,                    /* ROLE  */
    ROLLBACK = 635,                /* ROLLBACK  */
    ROLLUP = 636,                  /* ROLLUP  */
    ROW = 637,                     /* ROW  */
    ROWS = 638,                    /* ROWS  */
    RULE = 639,                    /* RULE  */
    SAMPLE = 640,                  /* SAMPLE  */
    SAVEPOINT = 641,               /* SAVEPOINT  */
    SCHEMA = 642,                  /* SCHEMA  */
    SCHEMAS = 643,                 /* SCHEMAS  */
    SCOPE = 644,                   /* SCOPE  */
    SCROLL = 645,                  /* SCROLL  */
    SEARCH = 646,                  /* SEARCH  */
    SECOND_P = 647,                /* SECOND_P  */
    SECONDS_P = 648,               /* SECONDS_P  */
    SECRET = 649,                  /* SECRET  */
    SECURITY = 650,                /* SECURITY  */
    SELECT = 651,                  /* SELECT  */
    SEMI = 652,                    /* SEMI  */
    SEQUENCE = 653,                /* SEQUENCE  */
    SEQUENCES = 654,               /* SEQUENCES  */
    SERIALIZABLE = 655,            /* SERIALIZABLE  */
    SERVER = 656,                  /* SERVER  */
    SESSION = 657,                 /* SESSION  */
    SET = 658,                     /* SET  */
    SETOF = 659,                   /* SETOF  */
    SETS = 660,                    /* SETS  */
    SHARE = 661,                   /* SHARE  */
    SHOW = 662,                    /* SHOW  */
    SIMILAR = 663,                 /* SIMILAR  */
    SIMPLE = 664,                  /* SIMPLE  */
    SKIP = 665,                    /* SKIP  */
    SMALLINT = 666,                /* SMALLINT  */
    SNAPSHOT = 667,                /* SNAPSHOT  */
    SOME = 668,                    /* SOME  */
    SORTED = 669,                  /* SORTED  */
    SOURCE_P = 670,                /* SOURCE_P  */
    SQL_P = 671,                   /* SQL_P  */
    STABLE = 672,                  /* STABLE  */
    STANDALONE_P = 673,            /* STANDALONE_P  */
    START = 674,                   /* START  */
    STATEMENT = 675,               /* STATEMENT  */
    STATISTICS = 676,              /* STATISTICS  */
    STDIN = 677,                   /* STDIN  */
    STDOUT = 678,                  /* STDOUT  */
    STORAGE = 679,                 /* STORAGE  */
    STORED = 680,                  /* STORED  */
    STRICT_P = 681,                /* STRICT_P  */
    STRIP_P = 682,                 /* STRIP_P  */
    STRUCT = 683,                  /* STRUCT  */
    SUBSCRIPTION = 684,            /* SUBSCRIPTION  */
    SUBSTRING = 685,               /* SUBSTRING  */
    SUMMARIZE = 686,               /* SUMMARIZE  */
    SYMMETRIC = 687,               /* SYMMETRIC  */
    SYSID = 688,                   /* SYSID  */
    SYSTEM_P = 689,                /* SYSTEM_P  */
    TABLE = 690,                   /* TABLE  */
    TABLES = 691,                  /* TABLES  */
    TABLESAMPLE = 692,             /* TABLESAMPLE  */
    TABLESPACE = 693,              /* TABLESPACE  */
    TARGET_P = 694,                /* TARGET_P  */
    TEMP = 695,                    /* TEMP  */
    TEMPLATE = 696,                /* TEMPLATE  */
    TEMPORARY = 697,               /* TEMPORARY  */
    TEXT_P = 698,                  /* TEXT_P  */
    THEN = 699,                    /* THEN  */
    TIES = 700,                    /* TIES  */
    TIME = 701,                    /* TIME  */
    TIMESTAMP = 702,               /* TIMESTAMP  */
    TO = 703,                      /* TO  */
    TRAILING = 704,                /* TRAILING  */
    TRANSACTION = 705,             /* TRANSACTION  */
    TRANSFORM = 706,               /* TRANSFORM  */
    TREAT = 707,                   /* TREAT  */
    TRIGGER = 708,                 /* TRIGGER  */
    TRIM = 709,                    /* TRIM  */
    TRUE_P = 710,                  /* TRUE_P  */
    TRUNCATE = 711,                /* TRUNCATE  */
    TRUSTED = 712,                 /* TRUSTED  */
    TRY_CAST = 713,                /* TRY_CAST  */
    TYPE_P = 714,                  /* TYPE_P  */
    TYPES_P = 715,                 /* TYPES_P  */
    UNBOUNDED = 716,               /* UNBOUNDED  */
    UNCOMMITTED = 717,             /* UNCOMMITTED  */
    UNENCRYPTED = 718,             /* UNENCRYPTED  */
    UNION = 719,                   /* UNION  */
    UNIQUE = 720,                  /* UNIQUE  */
    UNKNOWN = 721,                 /* UNKNOWN  */
    UNLISTEN = 722,                /* UNLISTEN  */
    UNLOGGED = 723,                /* UNLOGGED  */
    UNPACK = 724,                  /* UNPACK  */
    UNPIVOT = 725,                 /* UNPIVOT  */
    UNTIL = 726,                   /* UNTIL  */
    UPDATE = 727,                  /* UPDATE  */
    USE_P = 728,                   /* USE_P  */
    USER = 729,                    /* USER  */
    USING = 730,                   /* USING  */
    VACUUM = 731,                  /* VACUUM  */
    VALID = 732,                   /* VALID  */
    VALIDATE = 733,                /* VALIDATE  */
    VALIDATOR = 734,               /* VALIDATOR  */
    VALUE_P = 735,                 /* VALUE_P  */
    VALUES = 736,                  /* VALUES  */
    VARCHAR = 737,                 /* VARCHAR  */
    VARIABLE_P = 738,              /* VARIABLE_P  */
    VARIADIC = 739,                /* VARIADIC  */
    VARYING = 740,                 /* VARYING  */
    VERBOSE = 741,                 /* VERBOSE  */
    VERSION_P = 742,               /* VERSION_P  */
    VIEW = 743,                    /* VIEW  */
    VIEWS = 744,                   /* VIEWS  */
    VIRTUAL = 745,                 /* VIRTUAL  */
    VOLATILE = 746,                /* VOLATILE  */
    WEEK_P = 747,                  /* WEEK_P  */
    WEEKS_P = 748,                 /* WEEKS_P  */
    WHEN = 749,                    /* WHEN  */
    WHERE = 750,                   /* WHERE  */
    WHITESPACE_P = 751,            /* WHITESPACE_P  */
    WINDOW = 752,                  /* WINDOW  */
    WITH = 753,                    /* WITH  */
    WITHIN = 754,                  /* WITHIN  */
    WITHOUT = 755,                 /* WITHOUT  */
    WORK = 756,                    /* WORK  */
    WRAPPER = 757,                 /* WRAPPER  */
    WRITE_P = 758,                 /* WRITE_P  */
    XML_P = 759,                   /* XML_P  */
    XMLATTRIBUTES = 760,           /* XMLATTRIBUTES  */
    XMLCONCAT = 761,               /* XMLCONCAT  */
    XMLELEMENT = 762,              /* XMLELEMENT  */
    XMLEXISTS = 763,               /* XMLEXISTS  */
    XMLFOREST = 764,               /* XMLFOREST  */
    XMLNAMESPACES = 765,           /* XMLNAMESPACES  */
    XMLPARSE = 766,                /* XMLPARSE  */
    XMLPI = 767,                   /* XMLPI  */
    XMLROOT = 768,                 /* XMLROOT  */
    XMLSERIALIZE = 769,            /* XMLSERIALIZE  */
    XMLTABLE = 770,                /* XMLTABLE  */
    YEAR_P = 771,                  /* YEAR_P  */
    YEARS_P = 772,                 /* YEARS_P  */
    YES_P = 773,                   /* YES_P  */
    ZONE = 774,                    /* ZONE  */
    NOT_LA = 775,                  /* NOT_LA  */
    NULLS_LA = 776,                /* NULLS_LA  */
    WITH_LA = 777,                 /* WITH_LA  */
    POSTFIXOP = 778,               /* POSTFIXOP  */
    UMINUS = 779                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 13 "third_party/libpg_query/grammar/grammar.y"

	core_YYSTYPE		core_yystype;
	/* these fields must match core_YYSTYPE: */
	int					ival;
	char				*str;
	const char			*keyword;
	const char          *conststr;

	char				chr;
	bool				boolean;
	PGJoinType			jtype;
	PGDropBehavior		dbehavior;
	PGOnCommitAction		oncommit;
	PGOnCreateConflict		oncreateconflict;
	PGList				*list;
	PGNode				*node;
	PGValue				*value;
	PGObjectType			objtype;
	PGTypeName			*typnam;
	PGObjectWithArgs		*objwithargs;
	PGDefElem				*defelt;
	PGSortBy				*sortby;
	PGWindowDef			*windef;
	PGJoinExpr			*jexpr;
	PGIndexElem			*ielem;
	PGAlias				*alias;
	PGRangeVar			*range;
	PGIntoClause			*into;
	PGCTEMaterialize			ctematerialize;
	PGWithClause			*with;
	PGInferClause			*infer;
	PGOnConflictClause	*onconflict;
	PGOnConflictActionAlias onconflictshorthand;
	PGAIndices			*aind;
	PGResTarget			*target;
	PGInsertStmt			*istmt;
	PGVariableSetStmt		*vsetstmt;
	PGOverridingKind       override;
	PGSortByDir            sortorder;
	PGSortByNulls          nullorder;
	PGIgnoreNulls          ignorenulls;
	PGConstrType           constr;
	PGLockClauseStrength lockstrength;
	PGLockWaitPolicy lockwaitpolicy;
	PGSubLinkType subquerytype;
	PGViewCheckOption viewcheckoption;
	PGInsertColumnOrder bynameorposition;
	PGLoadInstallType loadinstalltype;
	PGTransactionStmtType transactiontype;
	PGMergeAction mergeaction;

#line 640 "third_party/libpg_query/grammar/grammar_out.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif




int base_yyparse (core_yyscan_t yyscanner);


#endif /* !YY_BASE_YY_THIRD_PARTY_LIBPG_QUERY_GRAMMAR_GRAMMAR_OUT_HPP_INCLUDED  */
