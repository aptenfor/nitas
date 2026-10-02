#include "chunk.h"
#include "imm.h"

void NitasChunk_init(NitasChunk *self)
{
	self->code =  nitas_malloc(5096);
	self->count = 0;
}

void NitasChunk_destroy(NitasChunk *self)
{
	nitas_free(self->code);
}

void NitasChunk_write_instruction(NitasChunk *self, NitasOpCode opcode,
...)
{
	va_list ap;
	self->code[self->count] = opcode;
	va_start(ap, opcode);
	if (opcode == NITAS_OP_ADD)
	{
		for (int i = 0;i < 3;i++)
		{
			self->code[self->count+i+1] = va_arg(ap, int);
		}
	}
	else if (opcode == NITAS_OP_LOADI)
	{
		self->code[self->count+1] = va_arg(ap, int);
		NitasImm imm;
		NitasImm_init(&imm, va_arg(ap, int));
		NitasImm_to_char(&imm, &(self->code[self->count+2]));
	}
	va_end(ap);
	self->count += NITAS_INSTRUCTION_SIZE;
}