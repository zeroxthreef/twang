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

#ifndef LEXER_H__
#define LEXER_H__

#ifdef __cplusplus
extern "C" {
#endif

/* === */

#include "util.h"


typedef struct
{
	char *str, *path;
	uint8_t type;
	size_t line, column;
} twang_token_t;


typedef struct
{
	twang_token_t *tokens;
	size_t token_amount, lex_progress, program_length;
	char *program_str, *program_path;
} twang_lexer_ctx_t;


/* initialize the lexer context and pass a string */
int twang_lexer_init(twang_t *compiler, twang_lexer_ctx_t *lexer, char *program_str, char *program_path, char *program_name);

/* destroy the lexer context */
int twang_lexer_destroy(twang_t *compiler, twang_lexer_ctx_t *lexer);

/* lex the string the context was initialized to */
int twang_lexer_string(twang_t *compiler, twang_lexer_ctx_t *lexer);


/* === */

#ifdef __cplusplus
}
#endif

#endif