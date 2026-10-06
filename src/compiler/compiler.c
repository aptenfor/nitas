#include "compiler.h"

#define NITAS_SRC_BUF_SIZE 600000
void NitasCompiler_init(NitasCompiler *self)
{
	self->src = nitas_malloc(NITAS_SRC_BUF_SIZE);
}
void NitasCompiler_destroy(NitasCompiler *self)
{
	nitas_free(self->src);
}
int NitasCompiler_compile(NitasCompiler *self, char *file, NitasChunk *chunk)
{
	self->line = 0;
	self->chunk = chunk;
	
	FILE *fp = fopen(file, "r");
	if (fp == NULL)
	{
		perror("fopen");
		return -1;
	}
	
	while (fgets(self->src, NITAS_SRC_BUF_SIZE, fp) != NULL)
	{
		char instruction[100];
		if (sscanf(self->src, "%s", instruction) == 1)
		{
			if (strcmp(instruction, "add") == 0)
			{
				int rd, rs1, rs2;
				if (sscanf(self->src, "%*s %d %d %d", &rd, &rs1, &rs2) == 3)
				{
					NitasChunk_write_instruction(self->chunk, NITAS_OP_ADD,
					rd, rs1, rs2);
				}
			}
			else if (strcmp(instruction, "sub") == 0)
			{
				int rd, rs1, rs2;
				if (sscanf(self->src, "%*s %d %d %d", &rd, &rs1, &rs2) == 3)
				{
					NitasChunk_write_instruction(self->chunk, NITAS_OP_SUB,
					rd, rs1, rs2);
				}
			}
			else if (strcmp(instruction, "loadi") == 0)
			{
				int rd, imm;
				if (sscanf(self->src, "%*s %d %d", &rd, &imm) == 2)
				{
					NitasChunk_write_instruction(self->chunk, NITAS_OP_LOADI,
					rd, imm);
				}
			}
			else if (strcmp(instruction, "load") == 0)
			{
				int rd, rs;
				if (sscanf(self->src, "%*s %d %d", &rd, &rs) == 2)
				{
					NitasChunk_write_instruction(self->chunk, NITAS_OP_LOAD, rd, rs);
				}
			}
			else if (strcmp(instruction, "store") == 0)
			{
				int rs1, rs2;
				if (sscanf(self->src, "%*s %d %d", &rs1, &rs2) == 2)
				{
					NitasChunk_write_instruction(self->chunk, NITAS_OP_STORE, rs1, rs2);
				}
			}
			else if (strcmp(instruction, "ecall") == 0)
			{
				NitasChunk_write_instruction(self->chunk, NITAS_OP_ECALL, NULL);
			}
			else
			{
				printf("error: 未知指令[%s] 行[%lld]\n", instruction, self->line);
				return -2;
			}
			self->line ++;
		}
		
	}
	fclose(fp);
}