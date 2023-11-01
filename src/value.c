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