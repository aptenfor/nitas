#include "chunk.h"
#include "compiler.h"

int main(int argc, char **argv)
{
	if (argc > 1 && strcmp(argv[1], "run") == 0)
	{
		NitasCompiler compiler;
		NitasCompiler_init(&compiler);
		NitasChunk chunk;
		NitasChunk_init(&chunk);
		
		NitasCompiler_compile(&compiler, argv[2], &chunk);
		
		NitasChunk_destroy(&chunk);
		NitasCompiler_destroy(&compiler);
	}
	return 0;
}
