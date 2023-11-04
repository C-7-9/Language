#include <stdlib.h>
#include <string.h>
#include "memory.h"

int
memory_new_variable(struct memory *mem, char *name, struct value var)
{
	if (mem->value == NULL)
		return -1;

	mem->value = realloc(mem->value, (mem->len + 1) * sizeof(struct value));
	mem->value[mem->len] = var;
	strcpy(mem->name[mem->len], name);
	mem->len++;

	return 0;
}

int
memory_get_variable(struct memory *mem, char *name, struct value *value)
{
	if (mem->value == NULL || mem->len == 0)
		return -1;
	
	for (size_t i = mem->len - 1; i; i--) {
		if (!strcmp(mem->name[i], name)) {
			*value = mem->value[i];
			return 0;
		}
	}

	return -1;
}
