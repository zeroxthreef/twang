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

#ifndef TWANG_H__
#define TWANG_H__

#ifdef __cplusplus
extern "C" {
#endif

/* === */

#include "util.h"
#include "lexer.h"
#include "parser.h"
#include "ir.h"


typedef struct twang_t twang_t;
typedef struct twang_module_t twang_module_t;

struct twang_t
{
	void *user_data;
	uint32_t *flags;

	twang_module_t main;
};

struct twang_module_t
{
	char *name, *path;
	twang_module_t *child, *next;
	twang_node_t *ast;
	/* twang_ir_t *ir; */
};




/* === */

#ifdef __cplusplus
}
#endif

#endif