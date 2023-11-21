#include "value.h"
#include <string.h>
#include <stdlib.h>
#include <math.h>

int
value_init_num(struct value *val, char *num)
{
	val->type = NUM;
	val->data.num = atof(num);

	return 0;
}

int
value_init_txt(struct value *val, char *txt)
{
	val->type = TXT;
	size_t txt_len = strlen(txt) + 1;
	val->data.txt = malloc(txt_len);
	if (var->data.txt == NULL)
		return -1;
	memcpy(val->data.txt, txt, txt_len);
	return 0;
}

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

int
value_txt_pop(struct value *val, char *ch)
{
    if(val->type != TXT || val->data.txt == NULL)
        return -1;

    int len = strlen(val->data.txt);

    //문자열이 비어있는 경우 -1 반환
    if(len == 0)
        return -1;
    //문자열 끝에 있는 문자 삭제 후 char *에 대입
    *ch = val->data.txt[len - 1];
    val->data.txt[len - 1] = '\0';

    val->data.txt = realloc(val->data.txt, len);
    return 0;
}

int
value_txt_insert(struct value *val, char ch, int in)
{
	if (val->type != TXT || val->data.txt == NULL)
		return -1;

	int len = strlen(val->data.txt);

	if (in < 0 || in > len)
		return -1;

	val->data.txt = realloc(val->data.txt, (len + 2));

	memmove(val->data.txt + in + 1, val->data.txt + in, (len - in + 1));

	val->data.txt[in] = ch;

	return 0;
}

int
value_txt_remove(struct value *val, char *ch, int in)
{
	if(val->type != TXT || val->data.txt == NULL)
		return -1;

	int lenth = strlen(val->data.txt);

	if(in < 0 || in >= lenth)
		return -1;

	*ch = val->data.txt[in];

	memmove(val->data.txt + in, val->data.txt + in + 1,(lenth-in));

	val-> data.txt = realloc(val->data.txt, lenth);
	return 0;
}

int
value_txt_get(struct value *val, char *ch, int in)
{
	if(val->type != TXT || val->data.txt == NULL)
		return -1;

	int lenth = strlen(val->data.txt);

	if(in < 0 || in >= lenth)
		return -1;

	*ch = val->data.txt[in];

	return 0;
}

int
value_txt_append(struct value *lft, struct value rgt)
{
	if (lft->type != TXT || rgt.type != TXT)
		return -1;
	
	int lftlenth = strlen(lft->data.txt);
	int rgtlenth = strlen(rgt.data.txt);

	lft->data.txt = realloc(lft->data.txt, (lftlenth + rgtlenth + 1));

	strcat(lft->data.txt, rgt.data.txt);

	return 0;
}

int
value_txt_split(struct value *lft, struct value *rgt, int in)
{
	if(lft->type != TXT || rgt->type != TXT || lft->data.txt == NULL)
		return -1;

	int lenth = strlen(lft->data.txt);

	if(in < 0 || in >= lenth)
		return -1;

	lft->data.txt = realloc(lft->data.txt, (in + 1));
	lft->data.txt[in] = '\0';
	
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
value_arr_remove(struct value *val, struct value *remove_value, int index)
{
    if (val->type != ARR)
        return -1;

    if (index < 0 || index >= val->data.arr.len)
        return -1;

    *remove_value = val->data.arr.arr_val[index];

    for (int i = index; i < val->data.arr.len - 1; i++)
        val->data.arr.arr_val[i] = val->data.arr.arr_val[i + 1];

    val->data.arr.len--;
	
    return 0;
}

int
value_arr_get(struct value *val, struct value *get_value, int index)
{
	if (val->type != ARR || index < 0 || index >= val->data.arr.len)
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

    for(int i = 0; i < left_val_lenght; i++)
        right_val_length++;

    val->data.arr.arr_val = 
		realloc(val->data.arr.arr_val, (left_val_lenght + right_val_length) * sizeof(struct value));

    val->data.arr.arr_val[left_val_lenght] = append_value;

    val->data.arr.len = left_val_lenght + 1;

    return 0;
}

int
value_arr_split(struct value *left, struct value *right, int split_num)
{
	if (left->type != ARR || right->type != ARR)
		return -1;

	int left_len = right->data.arr.len - split_num;
	left->data.arr.arr_val = 
		realloc(left->data.arr.arr_val, left_len * sizeof(struct value));
	left->data.arr.len = left_len;
	
	for (int i = split_num; i < left_len; i++)
		left->data.arr.arr_val[i - split_num] = right->data.arr.arr_val[i];

	return 0;
}
