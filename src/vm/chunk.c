#include "chunk.h"
#include "imm.h"

void NitasChunk_init(NitasChunk *self)
{
	self->code =  nitas_malloc(5096);
	self->pc = 0;
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
	self->count ++;
	va_start(ap, opcode);
	if (opcode == NITAS_OP_ADD)
	{
		for (int i = 0;i < 3;i++)
		{
			self->code[self->count] = va_arg(ap, int);
		}
	}
	else if (opcode == NITAS_OP_LOADI)
	{
		self->code[self->count] = va_arg(ap, int);
		self->count ++;
		NitasImm imm;
		NitasImm_init(&imm, va_arg(ap, int));
		NitasImm_to_char(&imm, &(self->code[self->count]));
	}
	va_end(ap);
}