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
value_arr_push(struct value *val, struct value *new_value)
{
	if (val->type != ARR)
			return -1;

	int len = 0;

	if (val->data.arr != '\0') {
		// 계산된 배열 요소의 수를 가져옵니다.

		struct value *current = val->data.arr;
		
		while (current->type != NUM) {
			len++;
			current++;
		}
	}

	// 새로운 value 요소를 배열에 추가하기 위해 realloc을 사용합니다.
	val->data.arr = realloc(val->data.arr, (len + 2) * sizeof(struct value));

	if (val->data.arr == '\0') {
	    // 메모리 할당 실패 시 예외 처리
	    return -1;
	}

	// 새로운 value 요소를 배열에 복사합니다.
	val->data.arr[len] = *new_value;

	return 0;
}

int
value_arr_pop(struct value *, struct value *);

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
