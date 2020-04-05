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

#include "twang.h"

#include "util.h"
#include "lexer.h"
#include "parser.h"
#include "ir.h"

#include <stdio.h>
#include <string.h>



#ifdef TWANG_STANDALONE
int main(int argc, char **argv)
{
	twang_t compiler;


	memset(&compiler, 0, sizeof(twang_t));



	return 0;
}
#endif

int twang_init(twang_t *compiler)
{


	return 0;
}

int twang_destroy(twang_t *compiler)
{



	return 0;
}

int twang_compile_file(twang_t *compiler, char *path)
{
	char *program_str = NULL;


	compiler->main.name = path; /* TODO: get the text after the last fslash */
	compiler->main.path = path;

	/* TODO: read program string from file */
	if(twang_compile_module_string(compiler, &compiler->main, program_str))
	{

		return 1;
	}


	return 0;
}

int twang_compile_module_string(twang_t *compiler, twang_module_t *module, char *str)
{
	twang_lexer_ctx_t lex_ctx;


	/* lex */
	if(twang_lexer_init(compiler, &lex_ctx, str, module->path, module->name))
	{

		return 1;
	}

	/* parse */
	/* compile IR */
	/* send to target */


	/* NOTE: be sure to add module to global module list to reuse definitions and everything else */

	return 0;
}