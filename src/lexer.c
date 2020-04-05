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

#include "lexer.h"

#include "util.h"
#include "utf8.h"
#include "twang.h"

#include <stdio.h>
#include <string.h>


int twang_lexer_init(twang_t *compiler, twang_lexer_ctx_t *lexer, char *program_str, char *program_path, char *program_name)
{
	memset(&lexer, 0, sizeof(twang_lexer_ctx_t));


	return 0;
}

int twang_lexer_destroy(twang_t *compiler, twang_lexer_ctx_t *lexer)
{



	return 0;
}

int twang_lexer_string(twang_t *compiler, twang_lexer_ctx_t *lexer)
{
	size_t i;


	for(i = 0; i < lexer->program_length; ++i)
	{

	}

	return 0;
}