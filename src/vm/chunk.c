#include "chunk.h"

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
	if (opcode == NITAS_OP_ADD)
	{
		self->code[self->count] = NITAS_OP_ADD;
		va_start(ap, 3);
		self->count ++;
		for (int i = 0;i < 3;i++)
		{
			self->code[self->count] = va_arg(ap, int);
		}
	}
	va_end(ap);
}