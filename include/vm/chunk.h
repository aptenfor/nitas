#ifndef NITAS_CHUNK_H
#define NITAS_CHUNK_H

#include "common.h"

typedef char NitasSlot;


typedef enum NitasOpCode
{
	NITAS_OP_ADD,
} NitasOpCode;
struct NitasChunk
{
	NitasSlot *code;
	size_t pc;
	size_t count;
};
typedef struct NitasChunk NitasChunk; 
void NitasChunk_init(NitasChunk *self);
void NitasChunk_destroy(NitasChunk *self);
void NitasChunk_write_instruction(NitasChunk *self, NitasOpCode opcode,
...);

#define NITAS_INSTRUCTION_SIZE 4
#endif
