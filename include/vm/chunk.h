#ifndef NITAS_CHUNK_H
#define NITAS_CHUNK_H

#include "common.h"

typedef char NitasSlot;


typedef enum NitasOpCode
{
	NITAS_OP_ADD,
};
struct NitasChunk
{
	NitasSlot *code;
	size_t pc;
};
typedef struct NitasChunk NitasChunk; 
void NitasChunk_init(NitasChunk *self);
void NitasChunk_destroy(NitasChunk *self);
#endif
