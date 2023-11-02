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

int value_arr_insert(struct value *val, struct value insert_value, int index)
{
    // 자료형 타입이 arr인지 확인한다.
    if (val->type != ARR)
        return -1;

    // 삽입할 위치가 유효한지 확인한다.
    if (index < 0 || index > val->data.arr.len)
        return -1;
	
    // 삽입할 값을 저장한다.
    val->data.arr.arr_val[index] = insert_value;

    return 0;
}

int value_arr_insert(struct value *val, struct value insert_value, int position)
{
    // 자료형 타입이 arr인지 NULL인지 확인한다.
    if (val->type != ARR || val->data.arr.arr_val == NULL)
        return -1;

    // 유효한 삽입 위치를 확인합니다.
    if (position < 0 || position > val->data.arr.len)
        return -1;

    // 삽입 위치를 기준으로 배열을 확장합니다.
    val->data.arr.arr_val = realloc(val->data.arr.arr_val, (val->data.arr.len + 1) * sizeof(struct value));

    if (val->data.arr.arr_val == NULL)
        return -1;

    // 배열을 오른쪽으로 이동하여 삽입할 위치 확보
    for (int i = val->data.arr.len; i > position; i--) {
        val->data.arr.arr_val[i] = val->data.arr.arr_val[i - 1];
    }

    // 값을 삽입하고 배열 길이를 증가시킴
    val->data.arr.arr_val[position] = insert_value;
    val->data.arr.len++;

    return 0;
}






int
value_arr_remove(struct value *val, struct value remove_value, int index)
{
	// 자료형 타입이 arr인지 확인한다.
    if (val->type != ARR)
        return -1;

    // 삽입할 위치가 유효한지 확인한다.
    if (index < 0 || index > val->data.arr.len)
        return -1;
	
    remove_value = val->data.arr.arr_val[index];
    

	return 0;
}

int
value_arr_get(struct value *, struct value *, int);

// 배열 끝에 추가하기
void
value_arr_append(struct value *, struct value)
{
    // 자료형 타입이 arr인지 NULL인지 확인한다.
	if (val->type != ARR || val->data.arr.arr_val == NULL)
        return -1;

    // 유효한 삽입 위치를 확인합니다.
    if (position < 0 || position > val->data.arr.len)
        return -1;
}


// 배열 하나가 있으면 주어진 인덱스기준 왼쪽,오른쪽 나누기
int
value_arr_split(struct value *,  struct value *, int);
