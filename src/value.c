#include "value.h"
#include <math.h>

int
value_num_add(struct value *left, struct value right)
{
	if (left->type != NUM || right.type != NUM)
		return -1;
	
	left->data.num += right.data.num;
	return 0;
}

int
value_num_sub(struct value *left, struct value right)
{
	if (left->type != NUM || right.type != NUM)
		return -1;
	
	left->data.num -= right.data.num;
	return 0;
}

int
value_num_mul(struct value *left, struct value right)
{
	if (left->type != NUM || right.type != NUM)
		return -1;
	
	left->data.num *= right.data.num;
	return 0;
}

int
value_num_div(struct value *left, struct value right)
{
	if (left->type != NUM || right.type != NUM)
		return -1;
	
	left->data.num /= right.data.num;
	return 0;
}

int
value_num_rem(struct value *left, struct value right)
{
	if (left->type != NUM || right.type != NUM)
		return -1;
	
	left->data.num = fmod(left->data.num, right.data.num);
	return 0;
}

int
value_txt_push(struct value *val, char ch)
{
    if(val->type != TXT)
        return -1;

    int len = strlen(val->data.txt);
    
    val->data.txt = realloc(val->data.txt, (len + 2));
    val->data.txt[len] = ch;
    return 0;
}
