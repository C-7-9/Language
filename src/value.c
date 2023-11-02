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
value_arr_push(struct value *val, struct value push_value)
{
	if (val->type != ARR)
			return -1;	

	val->data.arr.arr_val = realloc(val->data.arr.arr_val, (val->data.arr.len + 1)*sizeof(struct value));
	val->data.arr.len++;
	val->data.arr.arr_val[val->data.arr.len-1] = push_value;
	
	return 0;
}

int
value_arr_pop(struct value *val, struct value *pop_value)
{
	if (val->type != ARR || val->data.arr.arr_val == NULL)
		return -1;
	
	*pop_value = val->data.arr.arr_val[val->data.arr.len-1];
	val->data.arr.len--;
	val->data.arr.arr_val = realloc(val->data.arr.arr_val, (val->data.arr.len - 1)*sizeof(struct value));
	
	return 0;	
}

int
value_arr_insert(struct value *, struct value, int);

int
value_arr_remove(struct value *, struct value *, int);

int
value_arr_get(struct value *, struct value *, int);

void
value_arr_append(struct value *, struct value);

int
value_arr_split(struct value *,  struct value *, int);
// 배열 하나가 있으면 주어진 인덱스기준 왼쪽,오른쪽 나누기