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
	//자료형 타입이 arr인지 확인
	if (val->type != ARR)
			return -1;	

	// arr안의 데이터 값을 arr안에 넣어주고 value의 크기만큼 메모리를 재할당
	val->data.arr.arr_val = realloc(val->data.arr.arr_val, (val->data.arr.len + 1)*sizeof(struct value));
	val->data.arr.len++;
	val->data.arr.arr_val[val->data.arr.len-1] = push_value;
	
	return 0;
}

int
value_arr_pop(struct value *val, struct value *pop_value)
{
	// 자료형 타입이 arr인지 NULL인지 확인한다.
	if (val->type != ARR || val->data.arr.arr_val == NULL)
		return -1;

	*pop_value = val->data.arr.arr_val[val->data.arr.len-1];
	val->data.arr.len--;
	val->data.arr.arr_val = realloc(val->data.arr.arr_val, (val->data.arr.len - 1)*sizeof(struct value));
	
	return 0;	
}

int 
value_arr_insert(struct value *val, struct value insert_value, int index)
{
    if (val->type != ARR)
        return -1;

    if (index < 0 || index > val->data.arr.len)
        return -1;

    val->data.arr.arr_val = realloc(val->data.arr.arr_val, (val->data.arr.len + 1) * sizeof(struct value));

    for (int i = val->data.arr.len; i > index; i--)
        val->data.arr.arr_val[i] = val->data.arr.arr_val[i-1];

    val->data.arr.arr_val[index] = insert_value;
    val->data.arr.len++;

    return 0;
}

int 
value_arr_remove(struct value *val, struct value *remove_value, int index) {
	
    if (val->type != ARR)
        return -1;

    if (index < 0 || index >= val->data.arr.len)
        return -1;

    *remove_value = val->data.arr.arr_val[index];

    for (int i = index; i < val->data.arr.len - 1; i++) {
        val->data.arr.arr_val[i] = val->data.arr.arr_val[i + 1];
    }

    val->data.arr.len--;
	
    return 0;
}

int
value_arr_get(struct value *val, struct value *get_value, int index)
{
	if (val->type != ARR)
        return -1;

    if (index < 0 || index >= val->data.arr.len)
        return -1;
	
	*get_value = val->data.arr.arr_val[index];
	return 0;
}

int 
value_arr_append(struct value *val, struct value append_value)
{
    if (val->type != ARR)
        return -1;
    
    int left_val_lenght = val->data.arr.len;
    int right_val_length= 0;

    for(int i = 0; i < left_val_lenght; i++){
        right_val_length++;
    }

    val->data.arr.arr_val = realloc(val->data.arr.arr_val, (left_val_lenght + right_val_length) * sizeof(struct value));

    val->data.arr.arr_val[left_val_lenght] = append_value;

    val->data.arr.len = left_val_lenght + 1;

    return 0;
}

int
value_arr_split(struct value *val,  struct value *split_arr, int split_num)
{
	if (val->type != ARR)
        return -1;

	for (int i = split_num; i < val->data.arr.len - 1; i++) {
        *split_arr->data.arr.arr_val = val->data.arr.arr_val[split_num];
    }

}