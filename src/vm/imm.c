#include "imm.h"
NITAS_STATIC_ASSERT(sizeof(int) == 4, sizeof_int_4);

void NitasImm_init(NitasImm *self, int i)
{
	self->i = i;
}
void NitasImm_to_char(NitasImm *self, char *dest)
{
	memcpy(dest, &self->i, sizeof(int));
}
void NitasImm_from_char(NitasImm *self, char *src)
{
	memcpy(&self->i, src, sizeof(int));
}