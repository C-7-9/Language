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



/*
 * 	문자 삽입
 *
 * 	만약 int가 문자열 인덱스 범위 안에 있다면
 * 		문자열에 char를 끼워넣기
 * 		0 반환
 * 		아니면
 * 		-1 반환
 */
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


/*
 * 	배열 삭제
 *
 * 	만약 배열 안에 인자가 있고, int가 문자열 인덱스 범위 안에 있다면
 * 		int에 해당하는 인자 삭제 후 struct value *에 대입
 * 		0 반환
 * 		아니면
 * 		-1 반환
 */
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

/*
 * 	문자 탐색
 *
 * 	만약 int가 문자열 인덱스 범위 안에 있다면
 * 		int에 해당하는 인자를 char *에 대입
 * 		0 반환
 * 		아니면
 * 		-1 반환
 */

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

// 배열 끝에 추가하기
int
value_arr_append(struct value *val, struct value append_value)
{
	if (val->type != ARR)
        return -1;
	val->data.arr.arr_val = realloc(val->data.arr.arr_val, (val->data.arr.len + 1) * sizeof(struct value));
	val->data.arr.arr_val[val->data.arr.len] = append_value;
	val->data.arr.len++;

	return 0;
}


// 배열 하나가 있으면 주어진 인덱스기준 왼쪽,오른쪽 나누기

/*
 * 	문자열 분할
 * 	
 * 	만약 int가 왼쪽 문자열 인덱스 범위 안에 있다면
 * 		int에 해당하는 인덱스부터 문자열 끝까지를 오른쪽 문자열 포인터에 대입
 * 		0 반환
 * 		아니면
 * 		-1 반환
 */
int
value_arr_split(struct value *val,  struct value *split_arr, int split_num)
{
	if (val->type != ARR)
        return -1;

	for (int i = split_num; i < val->data.arr.len - 1; i++) {
        *split_arr->data.arr.arr_val = val->data.arr.arr_val[split_num];
    }

}