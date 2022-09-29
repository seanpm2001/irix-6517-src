/* Copyright (C) 1979-1998 TcX AB & Monty Program KB & Detron HB

   This software is distributed with NO WARRANTY OF ANY KIND.  No author or
   distributor accepts any responsibility for the consequences of using it, or
   for whether it serves any particular purpose or works at all, unless he or
   she says so in writing.  Refer to the Free Public License (the "License")
   for full details.

   Every copy of this file must include a copy of the License, normally in a
   plain ASCII text file named PUBLIC.	The License grants you the right to
   copy, modify and redistribute this file, but only under certain conditions
   described in the License.  Among other things, the License requires that
   the copyright notice and this notice be preserved on all copies. */

/* This file includes all reserved words and functions */

typedef struct st_symbol {
  char	*name;
  uint	tok;
  uint length;
} SYMBOL;

/* We don't want to include sql_yacc.h into gen_lex_hash */

#ifdef NO_YACC_SYMBOLS
#define SYM(A) 0
#else
#define SYM(A) A
#endif

/*
** Symbols are breaked in to separated arrays to allow fieldnames with
** same name as functions
** Theese are kept sorted for human lookup (the symbols are hashed)
*/

static SYMBOL symbols[] = {
  { "&&",		SYM(AND),0},
  { "<",		SYM(LT),0},
  { "<=",		SYM(LE),0},
  { "<>",		SYM(NE),0},
  { "!=",		SYM(NE),0},
  { "=",		SYM(EQ),0},
  { ">",		SYM(GT_SYM),0},
  { ">=",		SYM(GE),0},
  { "<<",		SYM(SHIFT_LEFT),0},
  { ">>",		SYM(SHIFT_RIGHT),0},
  { "ACTION",		SYM(ACTION),0},
  { "ADD",		SYM(ADD),0},
  { "ALL",		SYM(ALL),0},
  { "ALTER",		SYM(ALTER),0},
  { "AFTER",		SYM(AFTER_SYM),0},
  { "AND",		SYM(AND),0},
  { "AS",		SYM(AS),0},
  { "ASC",		SYM(ASC),0},
  { "AVG",		SYM(AVG_SUM),0},
  { "AUTO_INCREMENT",	SYM(AUTO_INC),0},
  { "BETWEEN",		SYM(BETWEEN_SYM),0},
  { "BIGINT",		SYM(BIGINT),0},
  { "BIT",		SYM(BIT_SYM),0},
  { "BINARY",		SYM(BINARY),0},
  { "BLOB",		SYM(BLOB_SYM),0},
  { "BOOL",		SYM(BOOL_SYM),0},
  { "BOTH",		SYM(BOTH),0},
  { "BY",		SYM(BY),0},
  { "CASCADE",		SYM(CASCADE),0},
  { "CHAR",		SYM(CHAR_SYM),0},
  { "CHARACTER",	SYM(CHAR_SYM),0},
  { "CHANGE",		SYM(CHANGE),0},
  { "CHECK",		SYM(CHECK_SYM),0},
  { "COLUMN",		SYM(COLUMN_SYM),0},
  { "COLUMNS",		SYM(COLUMNS),0},
  { "CONSTRAINT",	SYM(CONSTRAINT),0},
  { "CREATE",		SYM(CREATE),0},
  { "CROSS",		SYM(CROSS),0},
  { "CURRENT_DATE",	SYM(CURDATE),0},
  { "CURRENT_TIME",	SYM(CURTIME),0},
  { "CURRENT_TIMESTAMP", SYM(NOW_SYM),0},
  { "DATA",		SYM(DATA_SYM),0},
  { "DATABASE",		SYM(DATABASE),0},
  { "DATABASES",	SYM(DATABASES),0},
  { "DATE",		SYM(DATE_SYM),0},
  { "DATETIME",		SYM(DATETIME),0},
  { "DAY",		SYM(DAY_SYM),0},
  { "DAY_HOUR",		SYM(DAY_HOUR_SYM),0},
  { "DAY_MINUTE",	SYM(DAY_MINUTE_SYM),0},
  { "DAY_SECOND",	SYM(DAY_SECOND_SYM),0},
  { "DAYOFMONTH",	SYM(DAY_OF_MONTH),0},
  { "DAYOFWEEK",	SYM(DAY_OF_WEEK),0},
  { "DAYOFYEAR",	SYM(DAY_OF_YEAR),0},
  { "DEC",		SYM(DECIMAL_SYM),0},
  { "DECIMAL",		SYM(DECIMAL_SYM),0},
  { "DEFAULT",		SYM(DEFAULT),0},
  { "DELETE",		SYM(DELETE_SYM),0},
  { "DESC",		SYM(DESC),0},
  { "DESCRIBE",		SYM(DESCRIBE),0},
  { "DISTINCT",		SYM(DISTINCT),0},
  { "DISTINCTROW",	SYM(DISTINCT),0},	/* Access likes this */
  { "DOUBLE",		SYM(DOUBLE_SYM),0},
  { "DROP",		SYM(DROP),0},
  { "ESCAPE",		SYM(ESCAPE_SYM),0},
  { "ESCAPED",		SYM(ESCAPED),0},
  { "ENCLOSED",		SYM(ENCLOSED),0},
  { "ENUM",		SYM(ENUM),0},
  { "EXPLAIN",		SYM(DESCRIBE),0},
  { "EXISTS",		SYM(EXISTS),0},
  { "FIELDS",		SYM(COLUMNS),0},
  { "FILE",		SYM(FILE_SYM),0},
  { "FIRST",		SYM(FIRST_SYM),0},
  { "FLOAT",		SYM(FLOAT_SYM),0},
  { "FLOAT4",		SYM(FLOAT_SYM),0},
  { "FLOAT8",		SYM(DOUBLE_SYM),0},
  { "FLUSH",		SYM(FLUSH_SYM),0},
  { "FOREIGN",		SYM(FOREIGN),0},
  { "FROM",		SYM(FROM),0},
  { "FOR",		SYM(FOR_SYM),0},
  { "FULL",		SYM(FULL),0},
  { "FUNCTION",		SYM(UDF_SYM),0},
  { "GLOBAL",		SYM(GLOBAL_SYM),0},		
  { "GRANT",		SYM(GRANT),0},
  { "GROUP",		SYM(GROUP),0},
  { "HAVING",		SYM(HAVING),0},
  { "HEAP",		SYM(HEAP_SYM),0},
  { "HIGH_PRIORITY",	SYM(HIGH_PRIORITY),0},
  { "HOUR",		SYM(HOUR_SYM),0},
  { "HOUR_MINUTE",	SYM(HOUR_MINUTE_SYM),0},
  { "HOUR_SECOND",	SYM(HOUR_SECOND_SYM),0},
  { "HOSTS",		SYM(HOSTS_SYM),0},
  { "IDENTIFIED",	SYM(IDENTIFIED_SYM),0},
  { "IGNORE",		SYM(IGNORE_SYM),0},
  { "IN",		SYM(IN_SYM),0},
  { "INDEX",		SYM(INDEX),0},
  { "INFILE",		SYM(INFILE),0},
  { "INSERT",		SYM(INSERT),0},
  { "INSERT_ID",	SYM(INSERT_ID),0},
  { "INT",		SYM(INT_SYM),0},
  { "INTEGER",		SYM(INT_SYM),0},
  { "INTERVAL",		SYM(INTERVAL_SYM),0},
  { "INT1",		SYM(TINYINT),0},
  { "INT2",		SYM(SMALLINT),0},
  { "INT3",		SYM(MEDIUMINT),0},
  { "INT4",		SYM(INT_SYM),0},
  { "INT8",		SYM(BIGINT),0},
  { "INTO",		SYM(INTO),0},
  { "IF",		SYM(IF),0},
  { "IS",		SYM(IS),0},
  { "ISAM",		SYM(ISAM_SYM),0},
  { "JOIN",		SYM(JOIN_SYM),0},
  { "KEY",		SYM(KEY_SYM),0},
  { "KEYS",		SYM(KEYS),0},
  { "KILL",		SYM(KILL_SYM),0},
  { "LAST_INSERT_ID",	SYM(LAST_INSERT_ID),0 },
  { "LEADING",		SYM(LEADING),0},
  { "LEFT",		SYM(LEFT),0},
  { "LIKE",		SYM(LIKE),0},
  { "LINES",		SYM(LINES),0},
  { "LIMIT",		SYM(LIMIT),0},
  { "LOAD",		SYM(LOAD),0},
  { "LOCAL",		SYM(LOCAL_SYM),0},
  { "LOCK",		SYM(LOCK_SYM),0},
  { "LOGS",		SYM(LOGS_SYM),0},
  { "LONG",		SYM(LONG_SYM),0},
  { "LONGBLOB",		SYM(LONGBLOB),0},
  { "LONGTEXT",		SYM(LONGTEXT),0},
  { "LOW_PRIORITY",	SYM(LOW_PRIORITY),0},
  { "MAX",		SYM(MAX_SUM),0},
  { "MATCH",		SYM(MATCH),0},
  { "MEDIUMBLOB",	SYM(MEDIUMBLOB),0},
  { "MEDIUMTEXT",	SYM(MEDIUMTEXT),0},
  { "MEDIUMINT",	SYM(MEDIUMINT),0},
  { "MIDDLEINT",	SYM(MEDIUMINT),0},	/* For powerbuilder */
  { "MINUTE",		SYM(MINUTE_SYM),0},
  { "MINUTE_SECOND",	SYM(MINUTE_SECOND_SYM),0},
  { "MONTH",		SYM(MONTH_SYM),0},
  { "MONTHNAME",	SYM(MONTH_NAME_SYM),0},
  { "MYISAM",		SYM(MYISAM_SYM),0},
  { "NATURAL",		SYM(NATURAL),0},
  { "NUMERIC",		SYM(NUMERIC_SYM),0},
  { "NO",		SYM(NO_SYM),0},
  { "NOT",		SYM(NOT),0},
  { "NULL",		SYM(NULL_SYM),0},
  { "ON",		SYM(ON),0},
  { "OPTIMIZE",		SYM(OPTIMIZE),0},
  { "OPTION",		SYM(OPTION),0},
  { "OPTIONALLY",	SYM(OPTIONALLY),0},
  { "OR",		SYM(OR),0},
  { "ORDER",		SYM(ORDER_SYM),0},
  { "OUTER",		SYM(OUTER),0},
  { "OUTFILE",		SYM(OUTFILE),0},
  { "PARTIAL",		SYM(PARTIAL),0},
  { "PASSWORD",		SYM(PASSWORD),0},
  { "PRECISION",	SYM(PRECISION),0},
  { "PRIMARY",		SYM(PRIMARY_SYM),0},
  { "PROCEDURE",	SYM(PROCEDURE),0},
  { "PROCESS"	,	SYM(PROCESS), 0},
  { "PROCESSLIST",	SYM(PROCESSLIST_SYM), 0},
  { "PRIVILEGES",	SYM(PRIVILEGES),0},
  { "READ",		SYM(READ_SYM),0},
  { "REAL",		SYM(REAL),0},
  { "REFERENCES",	SYM(REFERENCES),0},
  { "RELOAD",		SYM(RELOAD),0},
  { "REGEXP",		SYM(REGEXP),0 },
  { "RENAME",		SYM(RENAME),0},
  { "REPLACE",		SYM(REPLACE),0},
  { "RESTRICT",		SYM(RESTRICT),0},
  { "RETURNS",		SYM(UDF_RETURNS_SYM),0},
  { "REVOKE",		SYM(REVOKE),0},
  { "RLIKE",		SYM(REGEXP),0 },	/* Like in mSQL2 */
  { "ROW",		SYM(ROW_SYM),0 },
  { "ROWS",		SYM(ROWS_SYM),0 },
  { "SECOND",		SYM(SECOND_SYM),0 },
  { "SELECT",		SYM(SELECT_SYM),0},
  { "SET",		SYM(SET),0},
  { "SHOW",		SYM(SHOW),0},
  { "SHUTDOWN",		SYM(SHUTDOWN),0},
  { "SMALLINT",		SYM(SMALLINT),0},
  { "SONAME",		SYM(UDF_SONAME_SYM),0},
  { "SQL_BIG_TABLES",	SYM(SQL_BIG_TABLES),0},
  { "SQL_BIG_SELECTS",	SYM(SQL_BIG_SELECTS),0},
  { "SQL_LOW_PRIORITY_UPDATES",	SYM(SQL_LOW_PRIORITY_UPDATES),0},
  { "SQL_LOG_OFF",	SYM(SQL_LOG_OFF),0},
  { "SQL_LOG_UPDATE",	SYM(SQL_LOG_UPDATE),0},
  { "SQL_SELECT_LIMIT",	SYM(SQL_SELECT_LIMIT),0},
  { "SQL_SMALL_RESULT",	SYM(SQL_SMALL_RESULT),0},
  { "SQL_WARNINGS",	SYM(SQL_WARNINGS),0},
  { "STRAIGHT_JOIN",	SYM(STRAIGHT_JOIN),0},
  { "STARTING",		SYM(STARTING),0},
  { "STATUS",		SYM(STATUS_SYM),0},
  { "STRING",		SYM(STRING_SYM),0},
  { "TABLE",		SYM(TABLE_SYM),0},
  { "TABLES",		SYM(TABLES),0},
  { "TERMINATED",	SYM(TERMINATED),0},
  { "TEXT",		SYM(TEXT_SYM),0},
  { "TIME",		SYM(TIME_SYM),0},
  { "TIMESTAMP",	SYM(TIMESTAMP),0},
  { "TINYBLOB",		SYM(TINYBLOB),0},
  { "TINYTEXT",		SYM(TINYTEXT),0},
  { "TINYINT",		SYM(TINYINT),0},
  { "TRAILING",		SYM(TRAILING),0},
  { "TO",		SYM(TO_SYM),0},
  { "TYPE",		SYM(TYPE_SYM),0},
  { "USE",		SYM(USE_SYM),0},
  { "USING",		SYM(USING),0},
  { "UNIQUE",		SYM(UNIQUE_SYM),0},
  { "UNLOCK",		SYM(UNLOCK_SYM),0},
  { "UNSIGNED",		SYM(UNSIGNED),0},
  { "UPDATE",		SYM(UPDATE_SYM),0},
  { "USAGE",		SYM(USAGE),0},
  { "VALUES",		SYM(VALUES),0},
  { "VARCHAR",		SYM(VARCHAR),0},
  { "VARIABLES",	SYM(VARIABLES),0},
  { "VARYING",		SYM(VARYING),0},
  { "VARBINARY",	SYM(VARBINARY),0},
  { "WITH",		SYM(WITH),0},
  { "WRITE",		SYM(WRITE_SYM),0},
  { "WHERE",		SYM(WHERE),0},
  { "YEAR",		SYM(YEAR_SYM),0},
  { "YEAR_MONTH",	SYM(YEAR_MONTH_SYM),0},
  { "ZEROFILL",		SYM(ZEROFILL),0},
  { "||",		SYM(OR),0}
};


static SYMBOL sql_functions[] = {
  { "ABS",		SYM(ABS),0},
  { "ACOS",		SYM(ACOS),0},
  { "ADDDATE",		SYM(DATE_ADD_INTERVAL),0},
  { "ASCII",		SYM(ASCII),0},
  { "ASIN",		SYM(ASIN),0},
  { "ATAN",		SYM(ATAN),0},
  { "ATAN2",		SYM(ATAN),0},
  { "BIN",		SYM(BIN),0},
  { "BIT_COUNT",	SYM(BIT_COUNT),0},
  { "BIT_OR",		SYM(BIT_OR),0},
  { "BIT_AND",		SYM(BIT_AND),0},
  { "CEILING",		SYM(CEILING),0},
  { "CHAR_LENGTH",	SYM(LENGTH),0},
  { "CHARACTER_LENGTH",	SYM(LENGTH),0},
  { "CONCAT",		SYM(CONCAT),0},
  { "CONV",		SYM(CONV),0},
  { "COUNT",		SYM(COUNT_SUM),0},
  { "COS",		SYM(COS),0},
  { "COT",		SYM(COT),0},
  { "CURDATE",		SYM(CURDATE),0},
  { "CURTIME",		SYM(CURTIME),0},
  { "DATE_ADD",		SYM(DATE_ADD_INTERVAL),0},
  { "DATE_FORMAT",	SYM(DATE_FORMAT_SYM),0},
  { "DATE_SUB",		SYM(DATE_SUB_INTERVAL),0},
  { "DAYNAME",		SYM(DAYNAME),0},
  { "DECODE",		SYM(DECODE_SYM),0},
  { "DEGREES",		SYM(DEGREES),0},
  { "ELT",		SYM(ELT_FUNC),0},
  { "ENCODE",		SYM(ENCODE_SYM),0},
  { "ENCRYPT",		SYM(ENCRYPT),0},
  { "EXP",		SYM(EXP),0},
  { "FIELD",		SYM(FIELD_FUNC),0},	/* For compability */
  { "FIND_IN_SET",	SYM(FIND_IN_SET),0},
  { "FLOOR",		SYM(FLOOR),0},
  { "FORMAT",		SYM(FORMAT),0},
  { "FROM_DAYS",	SYM(FROM_DAYS),0},
  { "FROM_UNIXTIME",	SYM(FROM_UNIXTIME),0},
  { "GET_LOCK",		SYM(GET_LOCK),0},
  { "GREATEST",		SYM(GREATEST_SYM),0},
  { "GROUP_UNIQUE_USERS",	SYM(GROUP_UNIQUE_USERS),0},
  { "HEX",		SYM(HEX),0},
  { "IFNULL",		SYM(IFNULL),0},
  { "INSTR",		SYM(INSTR),0},			/* unireg function */
  { "ISNULL",		SYM(ISNULL),0},
  { "LCASE",		SYM(LCASE),0},
  { "LEAST",		SYM(LEAST_SYM),0},
  { "LOWER",		SYM(LCASE),0},
  { "LENGTH",		SYM(LENGTH),0},
  { "LOCATE",		SYM(LOCATE),0},
  { "LOG",		SYM(LOG),0},
  { "LOG10",		SYM(LOG10),0},
  { "LPAD",		SYM(LPAD), 0},
  { "LTRIM",		SYM(LTRIM),0},
  { "MAKE_SET",		SYM(MAKE_SET_SYM),0},
  { "MID",		SYM(SUBSTRING),0},	/* unireg function */
  { "MIN",		SYM(MIN_SUM),0},
  { "MOD",		SYM(MOD_SYM),0},
  { "NOW",		SYM(NOW_SYM),0},
  { "OCTET_LENGTH",	SYM(LENGTH),0},
  { "OCT",		SYM(OCT),0},
  { "PERIOD_ADD",	SYM(PERIOD_ADD),0},
  { "PERIOD_DIFF",	SYM(PERIOD_DIFF),0},
  { "PI",		SYM(PI_SYM),0},
  { "POSITION",		SYM(POSITION_SYM),0},
  { "POW",		SYM(POW),0},
  { "POWER",		SYM(POW),0},
  { "QUARTER",		SYM(QUARTER),0},
  { "RADIANS",		SYM(RADIANS),0},
  { "RAND",		SYM(RAND),0},
  { "RELEASE_LOCK",	SYM(RELEASE_LOCK),0},
  { "REPEAT",		SYM(REPEAT),0},
  { "REVERSE",		SYM(REVERSE),0},
  { "RIGHT",		SYM(RIGHT),0},
  { "ROUND",		SYM(ROUND),0},
  { "RPAD",		SYM(RPAD), 0},
  { "RTRIM",		SYM(RTRIM),0},
  { "SEC_TO_TIME",	SYM(SEC_TO_TIME),0},
  { "SESSION_USER",	SYM(USER),0},
  { "SUBDATE",		SYM(DATE_SUB_INTERVAL),0},
  { "SIGN",		SYM(SIGN),0},
  { "SIN",		SYM(SIN),0},
  { "SOUNDEX",		SYM(SOUNDEX),0},
  { "SPACE",		SYM(SPACE),0},
  { "SQRT",		SYM(SQRT),0},
  { "STD",		SYM(STD_SUM),0},
  { "STDDEV",		SYM(STD_SUM),0},
  { "STRCMP",		SYM(STRCMP),0},
  { "SUBSTRING",	SYM(SUBSTRING),0},
  { "SUBSTRING_INDEX",	SYM(SUBSTRING_INDEX),0},
  { "SUM",		SYM(SUM_SUM),0},
  { "SYSDATE",		SYM(NOW_SYM),0},
  { "SYSTEM_USER",	SYM(USER),0},
  { "TAN",		SYM(TAN),0},
  { "TIME_FORMAT",	SYM(TIME_FORMAT_SYM),0},
  { "TIME_TO_SEC",	SYM(TIME_TO_SEC),0},
  { "TO_DAYS",		SYM(TO_DAYS),0},	/* Convert string or number */
  { "TRIM",		SYM(TRIM),0},
  { "TRUNCATE",		SYM(TRUNCATE),0},
  { "UCASE",		SYM(UCASE),0},
  { "UPPER",		SYM(UCASE),0},
  { "UNIQUE_USERS",	SYM(UNIQUE_USERS),0},
  { "UNIX_TIMESTAMP",	SYM(UNIX_TIMESTAMP),0},
  { "USER",		SYM(USER),0},
  { "VERSION",		SYM(VERSION_SYM),0},
  { "WEEK",		SYM(WEEK_SYM),0},
  { "WEEKDAY",		SYM(WEEKDAY),0}
};