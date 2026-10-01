#include "compiler.h"

void NitasCompiler_init(NitasCompiler *self)
{
	self->src = nitas_malloc(600000);
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
	
	while (fgets(self->src, sizeof(self->src), fp) != NULL)
	{
		char instruction[100];
		if (sscanf(self->src, "%s", instruction))
		{
			if (strcmp(instruction, "add") == 0)
			{
				int rd, rs1, rs2;
				if (sscanf(self->src, "%s %d %d %d", &rd, &rs1, &rs2) == 3)
				{
					NitasChunk_write_instruction(self->chunk, NITAS_OP_ADD,
					rd, rs1, rs2);
				}
			}
			else if (strcmp(instruction, "loadi") == 0)
			{
				int rd, imm;
				if (sscanf(self->src, "%d %d", &rd, &imm) == 2)
				{
					NitasChunk_write_instruction(self->chunk, NITAS_OP_LOADI,
					rd, imm);
				}
			}
			else
			{
				printf("error: %lld\n", self->line);
				return -2;
			}
			self->line ++;
		}
		
	}
	fclose(fp);
}