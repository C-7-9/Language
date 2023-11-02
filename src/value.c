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

	*ch = val->data.txt[in]

	memmove(val->data.txt + in, val->data.txt + in + 1,(lenth-in))

	val-> data.txt = realloc(val->data.txt, lenth);
	return 0;
}

int
value_txt_get(struct value *val, char *ch, int in)
{
	if(val->type != TXT || val->data.txt == NULL)
		return -1;

	int lenth = strlen(val->data.txt)

	if(in < 0 || in >= lenth):
		return -1;

	*ch = val->data.txt[in]

	return 0;
}

void
value_txt_append(struct value *lft, struct value rgt)
{
	if(lft->type != TXT || rgt.type != TXT)
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
	if(lft->type != TXT || rgt->type != TXT || lft->data.txt ++ NULL)
		return -1;

	int lenth = strlen(lft->data.txt);

	if(in < 0 || in >= len)
		return -1;

	//뒷부분 잘 모르겠음 헬프 요망
}
