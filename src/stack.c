#include "stack.h"

int
stack_push(struct stack *stack, struct value item)
{
	if (stack->top == STACK_SIZE)
		return -1;
	
	stack->value[stack->top] = item;
	return 0;
}

int
stack_pop(struct stack *stack, struct value *item)
{
	if (!stack->top)
		return -1;
	
	*item = stack->value[stack->top];
	return 0;
}

struct value *
stack_top(struct stack *stack)
{
	if (stack->top == 0 || stack->top == STACK_SIZE)
		return NULL;
	
	return &stack->value[stack->top];
}
