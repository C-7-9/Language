#ifndef VAL
#define VAL

#include "value.h"

#endif

struct stack {
	struct value *values;	//value의 가변 길이 배열
	int size;				//스택 안에 있는 값들의 개수
};

/*
 *  values 가변 배열 끝에 새로운 value 이어붙이기
 */
void
stack_push(struct stack *, struct value);

/*
 * 	만약 스택에 값이 있다면
 * 		values 가변 배열 마지막에 있는 값을 삭제 후 struct value *에 대입
 * 		0 반환
 * 	아니면
 * 		-1 반환
 */
int
stack_pop(struct stack *, struct value *);

/*
 *  만약 스택에 값이 있다면
 *  	values 가변 배열 마지막에 있는 값의 포인터 반환
 *  아니면
 *  	NULL 반환
 */
struct value *
stack_last(struct stack *);
