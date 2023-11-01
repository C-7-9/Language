#ifndef VAL
#define VAL

#include "value.h"
#include <stddef.h>
#define STACK_SIZE 16

struct stack {
	struct value value[STACK_SIZE];
	size_t top;
};

int
stack_push(struct stack *, struct value);

int
stack_pop(struct stack *, struct value *);

struct value *
stack_top(struct stack *);

#endif
