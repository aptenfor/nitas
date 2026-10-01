#ifndef NITAS_IMM_H
#define NITAS_IMM_H

#include "common.h"

#define NITAS_IMM_SIZE 4
typedef struct NitasImm
{
	int i;
} NitasImm;
void NitasImm_init(NitasImm *self, int i);
void NitasImm_to_char(NitasImm *self, char *dest);
void NitasImm_from_char(NitasImm *self, char *src);

#endif