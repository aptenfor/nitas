#include "chunk.h"
#include "compiler.h"
#include "vm.h"

int main(int argc, char **argv)
{
	if (argc > 1 && strcmp(argv[1], "run") == 0)
	{
		NitasCompiler compiler;
		NitasCompiler_init(&compiler);
		NitasChunk chunk;
		NitasChunk_init(&chunk);
		NitasVM_init(&vm);
		
		NitasCompiler_compile(&compiler, argv[2], &chunk);
		printf("exit(%lld)", NitasVM_interpret(&vm, &chunk));
		
		NitasChunk_destroy(&chunk);
		NitasCompiler_destroy(&compiler);
		NitasVM_destroy(&vm);
	}
	return 0;
}
