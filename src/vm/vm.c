#include "vm.h"
#include "imm.h"

NitasVM vm;

void NitasVM_init(NitasVM *self)
{
	
}
void NitasVM_destroy(NitasVM *self)
{
	
}
NitasInt NitasVM_interpret(NitasVM *self, NitasChunk *chunk)
{
	while (self->pc < chunk->count)
	{
		if (chunk->code[self->pc] == NITAS_OP_ADD)
		{
			self->regs[chunk->code[self->pc+1]] = 
			self->regs[chunk->code[self->pc+2]] + self->regs[chunk->code[self->pc+3]]; 
		}
		else if (chunk->code[self->pc] == NITAS_OP_LOADI)
		{
			NitasImm imm;
			NitasImm_from_char(&imm, &(chunk->code[self->pc+2]));
			self->regs[chunk->code[self->pc+1]] = imm.i;
		}
		self->pc += NITAS_INSTRUCTION_SIZE;
	}
	return self->regs[1];
}