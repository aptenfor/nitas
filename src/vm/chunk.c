#include "chunk.h"

void NitasChunk_init(NitasChunk *self)
{
	self->code =  nitas_malloc(5096);
}

void NitasChunk_destroy(NitasChunk *self)
{
	nitas_free(self->code);
}
