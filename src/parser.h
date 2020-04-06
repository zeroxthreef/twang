/* This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <http://unlicense.org/> */

#ifndef PARSER_H__
#define PARSER_H__

#ifdef __cplusplus
extern "C" {
#endif

/* === */

#include "util.h"
#include "lexer.h"

enum
{
	TWANG_NODE_TYPE_NONE,
	TWANG_NODE_TYPE_EXPR_LITERAL,
	TWANG_NODE_TYPE_EXPR_OPERATION,
	TWANG_NODE_TYPE_LIST_EXPR,
	TWANG_NODE_TYPE_FOR,
	TWANG_NODE_TYPE_WHILE,
	TWANG_NODE_TYPE_COND,
	TWANG_NODE_TYPE_DECLARE_VAR,
	TWANG_NODE_TYPE_DEFINE_FUNC,
	TWANG_NODE_TYPE_DEFINE_STRUCT,
	TWANG_NODE_TYPE_STATEMENT,
	TWANG_NODE_TYPE_STATEMENT_JUMP,
	TWANG_NODE_TYPE_STATEMENT_LABEL,
	TWANG_NODE_TYPE_LIST_PARAMETER,
	TWANG_NODE_TYPE_IMPORT,
};

enum
{
	TWANG_EXPRESSION_ADD,
	TWANG_EXPRESSION_SUB,
	TWANG_EXPRESSION_MUL,
	TWANG_EXPRESSION_DIV,
	TWANG_EXPRESSION_MODULO,
	TWANG_EXPRESSION_BITWISE_AND,
	TWANG_EXPRESSION_BITWISE_OR,
	TWANG_EXPRESSION_BITWISE_NOT,
	TWANG_EXPRESSION_BITWISE_XOR,
	TWANG_EXPRESSION_BITWISE_SHIFTL,
	TWANG_EXPRESSION_BITWISE_SHIFTR,
	TWANG_EXPRESSION_LOGICAL_AND,
	TWANG_EXPRESSION_LOGICAL_OR,
	TWANG_EXPRESSION_LOGICAL_NOT, /* unary */
	TWANG_EXPRESSION_LOGICAL_GREATER,
	TWANG_EXPRESSION_LOGICAL_LESS,
	TWANG_EXPRESSION_LOGICAL_GREATER_EQUAL,
	TWANG_EXPRESSION_LOGICAL_LESS_EQUAL,
	TWANG_EXPRESSION_LOGICAL_EQUAL,
	TWANG_EXPRESSION_LOGICAL_NOT_EQUAL,
	TWANG_EXPRESSION_ASSIGN_ADD,
};

typedef struct twang_node_t twang_node_t;

typedef struct twang_node_expr_t twang_node_expr_t;
typedef struct twang_node_postfix_expr_t twang_node_postfix_expr_t;
typedef struct twang_node_unary_expr_t twang_node_unary_expr_t;
typedef struct twang_node_binary_expr_t twang_node_binary_expr_t;
typedef struct twang_node_ternary_expr_t twang_node_ternary_expr_t;
typedef struct twang_node_call_expr_t twang_node_call_expr_t;
typedef struct twang_node_list_expr_t twang_node_list_expr_t;

typedef struct twang_node_var_declaration_t twang_node_var_declaration_t;
typedef struct twang_node_func_definition_t twang_node_func_definition_t;
typedef struct twang_node_struct_definition_t twang_node_struct_definition_t;

typedef struct twang_node_statement_t twang_node_statement_t; /* 1 or more as a list */
typedef struct twang_node_jump_statement_t twang_node_jump_statement_t;
typedef struct twang_node_label_statement_t twang_node_label_statement_t;
typedef struct twang_node_for_statement_t twang_node_for_statement_t; /* add a do flag */
typedef struct twang_node_while_statement_t twang_node_while_statement_t; /* add a do flag */
typedef struct twang_node_cond_statement_t twang_node_cond_statement_t;
typedef struct twang_node_expr_statement_t twang_node_expr_statement_t;
typedef struct twang_node_import_statement_t twang_node_import_statement_t;

typedef struct twang_node_list_parameter_t twang_node_list_parameter_t;
typedef struct twang_node_list_struct_t twang_node_list_struct_t;



/* base node */
struct twang_node_t
{
	size_t line, column;
	uint8_t type;
};


/* expressions */

/* both literal and operation node types */
struct twang_node_expr_t
{
	size_t line, column;
	uint8_t type;
	/* === */
	union
	{
		/* TWANG_NODE_TYPE_EXPR_LITERAL, */
		twang_token_t *literal;
		/* TWANG_NODE_TYPE_EXPR_OPERATION, */
		twang_node_t *operation;
	};
};

struct twang_node_postfix_expr_t /* expr operation */
{
	size_t line, column;
	uint8_t type;
	/* === */
	uint8_t operation;
	union
	{
		twang_node_call_expr_t *call; /* call op */
		twang_node_t *expr; /* array subscript op, inc/dec */
		twang_token_t *identifier; /* struct member/import dot op, deref dot op */
	};
};

struct twang_node_unary_expr_t /* expr operation */
{
	size_t line, column;
	uint8_t type;
	/* === */
	uint8_t operation;
	twang_node_t *expr;
};

struct twang_node_binary_expr_t /* expr operation */
{
	size_t line, column;
	uint8_t type;
	/* === */
	uint8_t operation;
	twang_node_t *left, *right;
};

struct twang_node_ternary_expr_t /* expr operation */
{
	size_t line, column;
	uint8_t type;
	/* === */
	uint8_t operation;
	twang_node_t *left, *middle, *right;
};

struct twang_node_ternary_expr_t /* expr operation */
{
	size_t line, column;
	uint8_t type;
	/* === */
	uint8_t operation;
	twang_node_t *left, *middle, *right;
};

struct twang_node_call_expr_t
{
	size_t line, column;
	uint8_t type;
	/* === */
	twang_node_list_expr_t *expression_list;
};

struct twang_node_list_expr_t
{
	size_t line, column;
	uint8_t type;
	/* === */
	twang_node_list_expr_t *next;
	twang_node_expr_t *expr;
};

/* declarations & definitions */

struct twang_node_var_declaration_t
{
	size_t line, column;
	uint8_t type;
	/* === */
	uint8_t storage, var_type;
	twang_token_t *identifier;
	twang_node_expr_t *initializer; /* can be null */
	twang_node_var_declaration_t *next; /* if a list */
};

struct twang_node_func_definition_t
{
	size_t line, column;
	uint8_t type;
	/* === */
	twang_token_t *identifier;
	twang_node_list_parameter_t *parameters;
	twang_node_statement_t *body;
};

struct twang_node_struct_definition_t
{
	size_t line, column;
	uint8_t type;
	/* === */
	twang_token_t *identifier;
	twang_node_list_struct_t *member_declaration; /* a list of nodes */
};


/* statements */

struct twang_node_for_statement_t
{
	size_t line, column;
	uint8_t type;
	/* === */
	twang_node_statement_t *next;
	/* ===== */
	uint8_t do_prefix;
	twang_node_t *init; /* an expression or variable declaration */
	twang_node_expr_t *condition, *iteration;
	twang_node_statement_t *loop;
};

struct twang_node_while_statement_t
{
	size_t line, column;
	uint8_t type;
	/* === */
	twang_node_statement_t *next;
	/* ===== */
	uint8_t do_prefix;
	twang_node_expr_t *condition;
	twang_node_statement_t *loop;
};

struct twang_node_cond_statement_t
{
	size_t line, column;
	uint8_t type;
	/* === */
	twang_node_statement_t *next;
	/* ===== */
	twang_node_expr_t *condition; /* can be null if expected just else */
	twang_node_statement_t *success;
	twang_node_cond_statement_t *else_statement; /* can be an else if or just else */
};

struct twang_node_expr_statement_t
{
	size_t line, column;
	uint8_t type;
	/* === */
	twang_node_statement_t *next;
	/* ===== */
	twang_node_expr_t *expression;
};

struct twang_node_import_statement_t
{
	size_t line, column;
	uint8_t type;
	/* === */
	twang_node_statement_t *next;
	/* ===== */
	twang_node_expr_t *import_guide; /* uses the '.' postfix operator and identifiers. Verify its validity */
};


/* lists */

struct twang_node_list_parameter_t
{
	size_t line, column;
	uint8_t type;
	/* === */
	uint8_t storage, var_type;
	twang_token_t *identifier;
	twang_node_var_declaration_t *next;
};

struct twang_node_list_struct_t
{
	size_t line, column;
	uint8_t type;
	/* === */
	uint8_t var_or_func; /* 1 for var, 0 for func */
	union
	{
		twang_node_var_declaration_t *var_declatarion;
		twang_node_func_definition_t *func_declaration;
	};
	twang_node_var_declaration_t *next;
};


/* === */

#ifdef __cplusplus
}
#endif

#endif