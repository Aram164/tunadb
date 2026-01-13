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
    AVG_P = 306,                   /* AVG_P  */
    BACKWARD = 307,                /* BACKWARD  */
    BEFORE = 308,                  /* BEFORE  */
    BEGIN_P = 309,                 /* BEGIN_P  */
    BETWEEN = 310,                 /* BETWEEN  */
    BIGINT = 311,                  /* BIGINT  */
    BINARY = 312,                  /* BINARY  */
    BIT = 313,                     /* BIT  */
    BOOLEAN_P = 314,               /* BOOLEAN_P  */
    BOTH = 315,                    /* BOTH  */
    BY = 316,                      /* BY  */
    CACHE = 317,                   /* CACHE  */
    CALL_P = 318,                  /* CALL_P  */
    CALLED = 319,                  /* CALLED  */
    CASCADE = 320,                 /* CASCADE  */
    CASCADED = 321,                /* CASCADED  */
    CASE = 322,                    /* CASE  */
    CAST = 323,                    /* CAST  */
    CATALOG_P = 324,               /* CATALOG_P  */
    CENTURIES_P = 325,             /* CENTURIES_P  */
    CENTURY_P = 326,               /* CENTURY_P  */
    CHAIN = 327,                   /* CHAIN  */
    CHAR_P = 328,                  /* CHAR_P  */
    CHARACTER = 329,               /* CHARACTER  */
    CHARACTERISTICS = 330,         /* CHARACTERISTICS  */
    CHECK_P = 331,                 /* CHECK_P  */
    CHECKPOINT = 332,              /* CHECKPOINT  */
    CLASS = 333,                   /* CLASS  */
    CLOSE = 334,                   /* CLOSE  */
    CLUSTER = 335,                 /* CLUSTER  */
    COALESCE = 336,                /* COALESCE  */
    COLLATE = 337,                 /* COLLATE  */
    COLLATION = 338,               /* COLLATION  */
    COLUMN = 339,                  /* COLUMN  */
    COLUMNS = 340,                 /* COLUMNS  */
    COMMENT = 341,                 /* COMMENT  */
    COMMENTS = 342,                /* COMMENTS  */
    COMMIT = 343,                  /* COMMIT  */
    COMMITTED = 344,               /* COMMITTED  */
    COMPRESSION = 345,             /* COMPRESSION  */
    CONCURRENTLY = 346,            /* CONCURRENTLY  */
    CONFIGURATION = 347,           /* CONFIGURATION  */
    CONFLICT = 348,                /* CONFLICT  */
    CONNECTION = 349,              /* CONNECTION  */
    CONSTRAINT = 350,              /* CONSTRAINT  */
    CONSTRAINTS = 351,             /* CONSTRAINTS  */
    CONTENT_P = 352,               /* CONTENT_P  */
    CONTINUE_P = 353,              /* CONTINUE_P  */
    CONVERSION_P = 354,            /* CONVERSION_P  */
    COPY = 355,                    /* COPY  */
    COST = 356,                    /* COST  */
    COUNT_P = 357,                 /* COUNT_P  */
    CREATE_P = 358,                /* CREATE_P  */
    CROSS = 359,                   /* CROSS  */
    CSV = 360,                     /* CSV  */
    CUBE = 361,                    /* CUBE  */
    CURRENT_P = 362,               /* CURRENT_P  */
    CURSOR = 363,                  /* CURSOR  */
    CYCLE = 364,                   /* CYCLE  */
    DATA_P = 365,                  /* DATA_P  */
    DATABASE = 366,                /* DATABASE  */
    DAY_P = 367,                   /* DAY_P  */
    DAYS_P = 368,                  /* DAYS_P  */
    DEALLOCATE = 369,              /* DEALLOCATE  */
    DEC = 370,                     /* DEC  */
    DECADE_P = 371,                /* DECADE_P  */
    DECADES_P = 372,               /* DECADES_P  */
    DECIMAL_P = 373,               /* DECIMAL_P  */
    DECLARE = 374,                 /* DECLARE  */
    DEFAULT = 375,                 /* DEFAULT  */
    DEFAULTS = 376,                /* DEFAULTS  */
    DEFERRABLE = 377,              /* DEFERRABLE  */
    DEFERRED = 378,                /* DEFERRED  */
    DEFINE = 379,                  /* DEFINE  */
    DEFINER = 380,                 /* DEFINER  */
    DELETE_P = 381,                /* DELETE_P  */
    DELIMITER = 382,               /* DELIMITER  */
    DELIMITERS = 383,              /* DELIMITERS  */
    DEPENDS = 384,                 /* DEPENDS  */
    DESC_P = 385,                  /* DESC_P  */
    DESCRIBE = 386,                /* DESCRIBE  */
    DETACH = 387,                  /* DETACH  */
    DICTIONARY = 388,              /* DICTIONARY  */
    DISABLE_P = 389,               /* DISABLE_P  */
    DISCARD = 390,                 /* DISCARD  */
    DISTINCT = 391,                /* DISTINCT  */
    DO = 392,                      /* DO  */
    DOCUMENT_P = 393,              /* DOCUMENT_P  */
    DOMAIN_P = 394,                /* DOMAIN_P  */
    DOUBLE_P = 395,                /* DOUBLE_P  */
    DROP = 396,                    /* DROP  */
    EACH = 397,                    /* EACH  */
    ELSE = 398,                    /* ELSE  */
    ENABLE_P = 399,                /* ENABLE_P  */
    ENCODING = 400,                /* ENCODING  */
    ENCRYPTED = 401,               /* ENCRYPTED  */
    END_P = 402,                   /* END_P  */
    ENUM_P = 403,                  /* ENUM_P  */
    ERROR_P = 404,                 /* ERROR_P  */
    ESCAPE = 405,                  /* ESCAPE  */
    EVENT = 406,                   /* EVENT  */
    EXCEPT = 407,                  /* EXCEPT  */
    EXCLUDE = 408,                 /* EXCLUDE  */
    EXCLUDING = 409,               /* EXCLUDING  */
    EXCLUSIVE = 410,               /* EXCLUSIVE  */
    EXECUTE = 411,                 /* EXECUTE  */
    EXISTS = 412,                  /* EXISTS  */
    EXPLAIN = 413,                 /* EXPLAIN  */
    EXPORT_P = 414,                /* EXPORT_P  */
    EXPORT_STATE = 415,            /* EXPORT_STATE  */
    EXTENSION = 416,               /* EXTENSION  */
    EXTENSIONS = 417,              /* EXTENSIONS  */
    EXTERNAL = 418,                /* EXTERNAL  */
    EXTRACT = 419,                 /* EXTRACT  */
    FALSE_P = 420,                 /* FALSE_P  */
    FAMILY = 421,                  /* FAMILY  */
    FETCH = 422,                   /* FETCH  */
    FILTER = 423,                  /* FILTER  */
    FIRST_P = 424,                 /* FIRST_P  */
    FLOAT_P = 425,                 /* FLOAT_P  */
    FOLLOWING = 426,               /* FOLLOWING  */
    FOR = 427,                     /* FOR  */
    FORCE = 428,                   /* FORCE  */
    FOREIGN = 429,                 /* FOREIGN  */
    FORWARD = 430,                 /* FORWARD  */
    FREEZE = 431,                  /* FREEZE  */
    FROM = 432,                    /* FROM  */
    FULL = 433,                    /* FULL  */
    FUNCTION = 434,                /* FUNCTION  */
    FUNCTIONS = 435,               /* FUNCTIONS  */
    GENERATED = 436,               /* GENERATED  */
    GLOB = 437,                    /* GLOB  */
    GLOBAL = 438,                  /* GLOBAL  */
    GRANT = 439,                   /* GRANT  */
    GRANTED = 440,                 /* GRANTED  */
    GROUP_P = 441,                 /* GROUP_P  */
    GROUPING = 442,                /* GROUPING  */
    GROUPING_ID = 443,             /* GROUPING_ID  */
    GROUPS = 444,                  /* GROUPS  */
    HANDLER = 445,                 /* HANDLER  */
    HAVING = 446,                  /* HAVING  */
    HEADER_P = 447,                /* HEADER_P  */
    HELLO = 448,                   /* HELLO  */
    HOLD = 449,                    /* HOLD  */
    HOUR_P = 450,                  /* HOUR_P  */
    HOURS_P = 451,                 /* HOURS_P  */
    IDENTITY_P = 452,              /* IDENTITY_P  */
    IF_P = 453,                    /* IF_P  */
    IGNORE_P = 454,                /* IGNORE_P  */
    ILIKE = 455,                   /* ILIKE  */
    IMMEDIATE = 456,               /* IMMEDIATE  */
    IMMUTABLE = 457,               /* IMMUTABLE  */
    IMPLICIT_P = 458,              /* IMPLICIT_P  */
    IMPORT_P = 459,                /* IMPORT_P  */
    IN_P = 460,                    /* IN_P  */
    INCLUDE_P = 461,               /* INCLUDE_P  */
    INCLUDING = 462,               /* INCLUDING  */
    INCREMENT = 463,               /* INCREMENT  */
    INDEX = 464,                   /* INDEX  */
    INDEXES = 465,                 /* INDEXES  */
    INHERIT = 466,                 /* INHERIT  */
    INHERITS = 467,                /* INHERITS  */
    INITIALLY = 468,               /* INITIALLY  */
    INLINE_P = 469,                /* INLINE_P  */
    INNER_P = 470,                 /* INNER_P  */
    INOUT = 471,                   /* INOUT  */
    INPUT_P = 472,                 /* INPUT_P  */
    INSENSITIVE = 473,             /* INSENSITIVE  */
    INSERT = 474,                  /* INSERT  */
    INSTALL = 475,                 /* INSTALL  */
    INSTEAD = 476,                 /* INSTEAD  */
    INT_P = 477,                   /* INT_P  */
    INTEGER = 478,                 /* INTEGER  */
    INTERSECT = 479,               /* INTERSECT  */
    INTERVAL = 480,                /* INTERVAL  */
    INTO = 481,                    /* INTO  */
    INVOKER = 482,                 /* INVOKER  */
    IS = 483,                      /* IS  */
    ISNULL = 484,                  /* ISNULL  */
    ISOLATION = 485,               /* ISOLATION  */
    JOIN = 486,                    /* JOIN  */
    JSON = 487,                    /* JSON  */
    KEY = 488,                     /* KEY  */
    LABEL = 489,                   /* LABEL  */
    LAMBDA = 490,                  /* LAMBDA  */
    LANGUAGE = 491,                /* LANGUAGE  */
    LARGE_P = 492,                 /* LARGE_P  */
    LAST_P = 493,                  /* LAST_P  */
    LATERAL_P = 494,               /* LATERAL_P  */
    LEADING = 495,                 /* LEADING  */
    LEAKPROOF = 496,               /* LEAKPROOF  */
    LEFT = 497,                    /* LEFT  */
    LEVEL = 498,                   /* LEVEL  */
    LIKE = 499,                    /* LIKE  */
    LIMIT = 500,                   /* LIMIT  */
    LISTEN = 501,                  /* LISTEN  */
    LOAD = 502,                    /* LOAD  */
    LOCAL = 503,                   /* LOCAL  */
    LOCATION = 504,                /* LOCATION  */
    LOCK_P = 505,                  /* LOCK_P  */
    LOCKED = 506,                  /* LOCKED  */
    LOGGED = 507,                  /* LOGGED  */
    MACRO = 508,                   /* MACRO  */
    MAP = 509,                     /* MAP  */
    MAPPING = 510,                 /* MAPPING  */
    MATCH = 511,                   /* MATCH  */
    MATCH_RECOGNIZE = 512,         /* MATCH_RECOGNIZE  */
    MATCHED = 513,                 /* MATCHED  */
    MATERIALIZED = 514,            /* MATERIALIZED  */
    MAX_P = 515,                   /* MAX_P  */
    MAXVALUE = 516,                /* MAXVALUE  */
    MEASURES = 517,                /* MEASURES  */
    MERGE = 518,                   /* MERGE  */
    METHOD = 519,                  /* METHOD  */
    MICROSECOND_P = 520,           /* MICROSECOND_P  */
    MICROSECONDS_P = 521,          /* MICROSECONDS_P  */
    MILLENNIA_P = 522,             /* MILLENNIA_P  */
    MILLENNIUM_P = 523,            /* MILLENNIUM_P  */
    MILLISECOND_P = 524,           /* MILLISECOND_P  */
    MILLISECONDS_P = 525,          /* MILLISECONDS_P  */
    MIN_P = 526,                   /* MIN_P  */
    MINUTE_P = 527,                /* MINUTE_P  */
    MINUTES_P = 528,               /* MINUTES_P  */
    MINVALUE = 529,                /* MINVALUE  */
    MODE = 530,                    /* MODE  */
    MONTH_P = 531,                 /* MONTH_P  */
    MONTHS_P = 532,                /* MONTHS_P  */
    MOVE = 533,                    /* MOVE  */
    NAME_P = 534,                  /* NAME_P  */
    NAMES = 535,                   /* NAMES  */
    NATIONAL = 536,                /* NATIONAL  */
    NATURAL = 537,                 /* NATURAL  */
    NCHAR = 538,                   /* NCHAR  */
    NEW = 539,                     /* NEW  */
    NEXT = 540,                    /* NEXT  */
    NO = 541,                      /* NO  */
    NONE = 542,                    /* NONE  */
    NOT = 543,                     /* NOT  */
    NOTHING = 544,                 /* NOTHING  */
    NOTIFY = 545,                  /* NOTIFY  */
    NOTNULL = 546,                 /* NOTNULL  */
    NOWAIT = 547,                  /* NOWAIT  */
    NULL_P = 548,                  /* NULL_P  */
    NULLIF = 549,                  /* NULLIF  */
    NULLS_P = 550,                 /* NULLS_P  */
    NUMERIC = 551,                 /* NUMERIC  */
    OBJECT_P = 552,                /* OBJECT_P  */
    OF = 553,                      /* OF  */
    OFF = 554,                     /* OFF  */
    OFFSET = 555,                  /* OFFSET  */
    OIDS = 556,                    /* OIDS  */
    OLD = 557,                     /* OLD  */
    ON = 558,                      /* ON  */
    ONE = 559,                     /* ONE  */
    ONLY = 560,                    /* ONLY  */
    OPERATOR = 561,                /* OPERATOR  */
    OPTION = 562,                  /* OPTION  */
    OPTIONS = 563,                 /* OPTIONS  */
    OR = 564,                      /* OR  */
    ORDER = 565,                   /* ORDER  */
    ORDINALITY = 566,              /* ORDINALITY  */
    OTHERS = 567,                  /* OTHERS  */
    OUT_P = 568,                   /* OUT_P  */
    OUTER_P = 569,                 /* OUTER_P  */
    OVER = 570,                    /* OVER  */
    OVERLAPS = 571,                /* OVERLAPS  */
    OVERLAY = 572,                 /* OVERLAY  */
    OVERRIDING = 573,              /* OVERRIDING  */
    OWNED = 574,                   /* OWNED  */
    OWNER = 575,                   /* OWNER  */
    PARALLEL = 576,                /* PARALLEL  */
    PARSER = 577,                  /* PARSER  */
    PARTIAL = 578,                 /* PARTIAL  */
    PARTITION = 579,               /* PARTITION  */
    PARTITIONED = 580,             /* PARTITIONED  */
    PASSING = 581,                 /* PASSING  */
    PASSWORD = 582,                /* PASSWORD  */
    PAST = 583,                    /* PAST  */
    PATTERN = 584,                 /* PATTERN  */
    PER = 585,                     /* PER  */
    PERCENT = 586,                 /* PERCENT  */
    PERSISTENT = 587,              /* PERSISTENT  */
    PIVOT = 588,                   /* PIVOT  */
    PIVOT_LONGER = 589,            /* PIVOT_LONGER  */
    PIVOT_WIDER = 590,             /* PIVOT_WIDER  */
    PLACING = 591,                 /* PLACING  */
    PLANS = 592,                   /* PLANS  */
    POLICY = 593,                  /* POLICY  */
    POSITION = 594,                /* POSITION  */
    POSITIONAL = 595,              /* POSITIONAL  */
    PRAGMA_P = 596,                /* PRAGMA_P  */
    PRECEDING = 597,               /* PRECEDING  */
    PRECISION = 598,               /* PRECISION  */
    PREPARE = 599,                 /* PREPARE  */
    PREPARED = 600,                /* PREPARED  */
    PRESERVE = 601,                /* PRESERVE  */
    PRIMARY = 602,                 /* PRIMARY  */
    PRIOR = 603,                   /* PRIOR  */
    PRIVILEGES = 604,              /* PRIVILEGES  */
    PROCEDURAL = 605,              /* PROCEDURAL  */
    PROCEDURE = 606,               /* PROCEDURE  */
    PROGRAM = 607,                 /* PROGRAM  */
    PUBLICATION = 608,             /* PUBLICATION  */
    QUALIFY = 609,                 /* QUALIFY  */
    QUARTER_P = 610,               /* QUARTER_P  */
    QUARTERS_P = 611,              /* QUARTERS_P  */
    QUOTE = 612,                   /* QUOTE  */
    RANGE = 613,                   /* RANGE  */
    READ_P = 614,                  /* READ_P  */
    REAL = 615,                    /* REAL  */
    REASSIGN = 616,                /* REASSIGN  */
    RECHECK = 617,                 /* RECHECK  */
    RECURSIVE = 618,               /* RECURSIVE  */
    REF = 619,                     /* REF  */
    REFERENCES = 620,              /* REFERENCES  */
    REFERENCING = 621,             /* REFERENCING  */
    REFRESH = 622,                 /* REFRESH  */
    REINDEX = 623,                 /* REINDEX  */
    RELATIVE_P = 624,              /* RELATIVE_P  */
    RELEASE = 625,                 /* RELEASE  */
    RENAME = 626,                  /* RENAME  */
    REPEATABLE = 627,              /* REPEATABLE  */
    REPLACE = 628,                 /* REPLACE  */
    REPLICA = 629,                 /* REPLICA  */
    RESET = 630,                   /* RESET  */
    RESPECT_P = 631,               /* RESPECT_P  */
    RESTART = 632,                 /* RESTART  */
    RESTRICT = 633,                /* RESTRICT  */
    RETURNING = 634,               /* RETURNING  */
    RETURNS = 635,                 /* RETURNS  */
    REVOKE = 636,                  /* REVOKE  */
    RIGHT = 637,                   /* RIGHT  */
    ROLE = 638,                    /* ROLE  */
    ROLLBACK = 639,                /* ROLLBACK  */
    ROLLUP = 640,                  /* ROLLUP  */
    ROW = 641,                     /* ROW  */
    ROWS = 642,                    /* ROWS  */
    RULE = 643,                    /* RULE  */
    SAMPLE = 644,                  /* SAMPLE  */
    SAVEPOINT = 645,               /* SAVEPOINT  */
    SCHEMA = 646,                  /* SCHEMA  */
    SCHEMAS = 647,                 /* SCHEMAS  */
    SCOPE = 648,                   /* SCOPE  */
    SCROLL = 649,                  /* SCROLL  */
    SEARCH = 650,                  /* SEARCH  */
    SECOND_P = 651,                /* SECOND_P  */
    SECONDS_P = 652,               /* SECONDS_P  */
    SECRET = 653,                  /* SECRET  */
    SECURITY = 654,                /* SECURITY  */
    SELECT = 655,                  /* SELECT  */
    SEMI = 656,                    /* SEMI  */
    SEQUENCE = 657,                /* SEQUENCE  */
    SEQUENCES = 658,               /* SEQUENCES  */
    SERIALIZABLE = 659,            /* SERIALIZABLE  */
    SERVER = 660,                  /* SERVER  */
    SESSION = 661,                 /* SESSION  */
    SET = 662,                     /* SET  */
    SETOF = 663,                   /* SETOF  */
    SETS = 664,                    /* SETS  */
    SHARE = 665,                   /* SHARE  */
    SHOW = 666,                    /* SHOW  */
    SIMILAR = 667,                 /* SIMILAR  */
    SIMPLE = 668,                  /* SIMPLE  */
    SKIP = 669,                    /* SKIP  */
    SMALLINT = 670,                /* SMALLINT  */
    SNAPSHOT = 671,                /* SNAPSHOT  */
    SOME = 672,                    /* SOME  */
    SORTED = 673,                  /* SORTED  */
    SOURCE_P = 674,                /* SOURCE_P  */
    SQL_P = 675,                   /* SQL_P  */
    STABLE = 676,                  /* STABLE  */
    STANDALONE_P = 677,            /* STANDALONE_P  */
    START = 678,                   /* START  */
    STATEMENT = 679,               /* STATEMENT  */
    STATISTICS = 680,              /* STATISTICS  */
    STDIN = 681,                   /* STDIN  */
    STDOUT = 682,                  /* STDOUT  */
    STORAGE = 683,                 /* STORAGE  */
    STORED = 684,                  /* STORED  */
    STRICT_P = 685,                /* STRICT_P  */
    STRIP_P = 686,                 /* STRIP_P  */
    STRUCT = 687,                  /* STRUCT  */
    SUBSCRIPTION = 688,            /* SUBSCRIPTION  */
    SUBSTRING = 689,               /* SUBSTRING  */
    SUM_P = 690,                   /* SUM_P  */
    SUMMARIZE = 691,               /* SUMMARIZE  */
    SYMMETRIC = 692,               /* SYMMETRIC  */
    SYSID = 693,                   /* SYSID  */
    SYSTEM_P = 694,                /* SYSTEM_P  */
    TABLE = 695,                   /* TABLE  */
    TABLES = 696,                  /* TABLES  */
    TABLESAMPLE = 697,             /* TABLESAMPLE  */
    TABLESPACE = 698,              /* TABLESPACE  */
    TARGET_P = 699,                /* TARGET_P  */
    TEMP = 700,                    /* TEMP  */
    TEMPLATE = 701,                /* TEMPLATE  */
    TEMPORARY = 702,               /* TEMPORARY  */
    TEXT_P = 703,                  /* TEXT_P  */
    THEN = 704,                    /* THEN  */
    TIES = 705,                    /* TIES  */
    TIME = 706,                    /* TIME  */
    TIMESTAMP = 707,               /* TIMESTAMP  */
    TO = 708,                      /* TO  */
    TRAILING = 709,                /* TRAILING  */
    TRANSACTION = 710,             /* TRANSACTION  */
    TRANSFORM = 711,               /* TRANSFORM  */
    TREAT = 712,                   /* TREAT  */
    TRIGGER = 713,                 /* TRIGGER  */
    TRIM = 714,                    /* TRIM  */
    TRUE_P = 715,                  /* TRUE_P  */
    TRUNCATE = 716,                /* TRUNCATE  */
    TRUSTED = 717,                 /* TRUSTED  */
    TRY_CAST = 718,                /* TRY_CAST  */
    TYPE_P = 719,                  /* TYPE_P  */
    TYPES_P = 720,                 /* TYPES_P  */
    UNBOUNDED = 721,               /* UNBOUNDED  */
    UNCOMMITTED = 722,             /* UNCOMMITTED  */
    UNENCRYPTED = 723,             /* UNENCRYPTED  */
    UNION = 724,                   /* UNION  */
    UNIQUE = 725,                  /* UNIQUE  */
    UNKNOWN = 726,                 /* UNKNOWN  */
    UNLISTEN = 727,                /* UNLISTEN  */
    UNLOGGED = 728,                /* UNLOGGED  */
    UNPACK = 729,                  /* UNPACK  */
    UNPIVOT = 730,                 /* UNPIVOT  */
    UNTIL = 731,                   /* UNTIL  */
    UPDATE = 732,                  /* UPDATE  */
    USE_P = 733,                   /* USE_P  */
    USER = 734,                    /* USER  */
    USING = 735,                   /* USING  */
    VACUUM = 736,                  /* VACUUM  */
    VALID = 737,                   /* VALID  */
    VALIDATE = 738,                /* VALIDATE  */
    VALIDATOR = 739,               /* VALIDATOR  */
    VALUE_P = 740,                 /* VALUE_P  */
    VALUES = 741,                  /* VALUES  */
    VARCHAR = 742,                 /* VARCHAR  */
    VARIABLE_P = 743,              /* VARIABLE_P  */
    VARIADIC = 744,                /* VARIADIC  */
    VARYING = 745,                 /* VARYING  */
    VERBOSE = 746,                 /* VERBOSE  */
    VERSION_P = 747,               /* VERSION_P  */
    VIEW = 748,                    /* VIEW  */
    VIEWS = 749,                   /* VIEWS  */
    VIRTUAL = 750,                 /* VIRTUAL  */
    VOLATILE = 751,                /* VOLATILE  */
    WEEK_P = 752,                  /* WEEK_P  */
    WEEKS_P = 753,                 /* WEEKS_P  */
    WHEN = 754,                    /* WHEN  */
    WHERE = 755,                   /* WHERE  */
    WHITESPACE_P = 756,            /* WHITESPACE_P  */
    WINDOW = 757,                  /* WINDOW  */
    WITH = 758,                    /* WITH  */
    WITHIN = 759,                  /* WITHIN  */
    WITHOUT = 760,                 /* WITHOUT  */
    WORK = 761,                    /* WORK  */
    WRAPPER = 762,                 /* WRAPPER  */
    WRITE_P = 763,                 /* WRITE_P  */
    XML_P = 764,                   /* XML_P  */
    XMLATTRIBUTES = 765,           /* XMLATTRIBUTES  */
    XMLCONCAT = 766,               /* XMLCONCAT  */
    XMLELEMENT = 767,              /* XMLELEMENT  */
    XMLEXISTS = 768,               /* XMLEXISTS  */
    XMLFOREST = 769,               /* XMLFOREST  */
    XMLNAMESPACES = 770,           /* XMLNAMESPACES  */
    XMLPARSE = 771,                /* XMLPARSE  */
    XMLPI = 772,                   /* XMLPI  */
    XMLROOT = 773,                 /* XMLROOT  */
    XMLSERIALIZE = 774,            /* XMLSERIALIZE  */
    XMLTABLE = 775,                /* XMLTABLE  */
    YEAR_P = 776,                  /* YEAR_P  */
    YEARS_P = 777,                 /* YEARS_P  */
    YES_P = 778,                   /* YES_P  */
    ZONE = 779,                    /* ZONE  */
    NOT_LA = 780,                  /* NOT_LA  */
    NULLS_LA = 781,                /* NULLS_LA  */
    WITH_LA = 782,                 /* WITH_LA  */
    POSTFIXOP = 783,               /* POSTFIXOP  */
    UMINUS = 784                   /* UMINUS  */
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

#line 645 "third_party/libpg_query/grammar/grammar_out.hpp"

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
