#ifndef VAL
#define VAL

#include "value.h"
#include <stddef.h>
#define NAME_LEN 16

struct memory {
	char *name[NAME_LEN];
	struct value *value;
	size_t len;
};

int
memory_new_variable(struct memory *, char *, struct value);

int
memory_get_variable(struct memory *, char *, struct value);

#endif
