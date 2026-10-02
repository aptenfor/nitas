#ifndef NITAS_VM_H
#define NITAS_VM_H

#include "chunk.h"
typedef long long NitasReg;
#define NITAS_REG_COUNT 32

typedef long long NitasMem;
#define NITAS_MEM_COUNT 10000
struct NitasVM
{
	NitasReg regs[NITAS_REG_COUNT];
	NitasMem mem[NITAS_MEM_COUNT];
	NitasChunk *chunk;
	size_t pc;
};
typedef struct NitasVM NitasVM;
void NitasVM_init(NitasVM *self);
void NitasVM_destroy(NitasVM *self);
NitasInt NitasVM_interpret(NitasVM *self, NitasChunk *chunk);

extern NitasVM vm;

#endif