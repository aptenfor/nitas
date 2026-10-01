#ifndef NITAS_NITAS_COMPILER_H
#define NITAS_NITAS_COMPILER_H

#include "chunk.h"
typedef struct NitasCompiler
{
	NitasChunk *chunk;
	char *src;
	NitasInt line;
} NitasCompiler;
void NitasCompiler_init(NitasCompiler *self);
void NitasCompiler_destroy(NitasCompiler *self);
int NitasCompiler_compile(NitasCompiler *self, char *file, NitasChunk *chunk);

#endif