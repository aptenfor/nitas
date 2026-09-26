#include "chunk.h"

int main()
{
	NitasChunk chunk;
	NitasChunk_init(&chunk);
	NitasChunk_destroy(&chunk);
	return 0;
}
