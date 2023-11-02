struct value {
	enum type {
		NUM,
		TXT,
		ARR,
	} type;
	union {					// 유니온 - 스코프 안에 존재하는 필드 중 하나의 상태로만 존재
		double num;			// 64 비트 실수
		char *txt;			// 가변 길이 문자열
		struct value *arr;	// 가변 길이 값 배열
	} data;
};

/*******************************************힌트*****************************************
 * 포인터로 전달된 구조체 A에 대해서, A->foo의 형태로 그 구조체의 필드에 접근할 수 있다 *
 ****************************************************************************************/

/*
 * 	값 초기화
 *
 * 	파일에서 읽어온 문자열을 변수값으로 초기화
 * 	
 * 	만약 문자열의 형식이 각 자료형에 맞다면
 * 		문자열을 각 자료형으로 바꿔서 struct value 생성
 * 		struct value *에 대입
 * 		0 반환
 * 	아니면
 * 		-1 반환
 */
int
value_init_num(struct value *, char *);

int
value_init_txt(struct value *, char *);

int
value_init_arr(struct value *, char *);

/*
 *	대입 연산
 *
 *	왼쪽 struct value * -> 대입될 변수
 *	오른쪽 struct value -> 대입할 변수
 *	
 *	만약 두 변수의 자료형이 같다면
 *		오른쪽 변수의 값을 왼쪽 변수에 대입
 *		0 반환
 *	아니면
 *		-1 반환
 */
int
value_assign(struct value *, struct value);

/*
 *	자료형 변환
 *
 *	만약 자료형을 변환 할 수 있다면
 *		오른쪽 변수의 자료형을 바꾼 값을 왼쪽 변수에 대입
 *		0 반환
 *	아니면
 *		-1 반환
 */
int
value_to_num(struct value *, struct value);

int
value_to_txt(struct value *, struct value);

/*
 *	숫자 연산
 *
 *	만약 변수 자료형이 정수이거나 실수라면
 *		왼쪽 변수와 오른쪽 변수를 연산하여 오른쪽 변수에 대입
 *		0 반환
 *	아니면
 *		-1 반환
 */
int
value_num_add(struct value *, struct value);

int
value_num_sub(struct value *, struct value);

int
value_num_mul(struct value *, struct value);

int
value_num_div(struct value *, struct value);

int
value_num_rem(struct value *, struct value);

/*
 * 	문자 추가
 * 
 * 	문자열 끝에 문자 추가
 */
int
value_txt_push(struct value *, char);

/*
 * 	마지막 문자 삭제 
 * 
 * 	만약 문자열 안에 문자가 있다면
 * 		문자열 끝에 있는 문자 삭제 후 char *에 대입
 * 		0 반환
 * 	아니면
 * 		-1 반환
 */
int
value_txt_pop(struct value *, char *);

/*
 * 	문자 삽입
 *
 * 	만약 int가 문자열 인덱스 범위 안에 있다면
 * 		문자열에 char를 끼워넣기
 * 		0 반환
 * 	아니면
 * 		-1 반환
 */
int
value_txt_insert(struct value *, char, int);

/*
 * 	문자 삭제
 *
 * 	만약 문자열 안에 문자가 있고, int가 문자열 인덱스 범위 안에 있다면
 * 		int에 해당하는 문자 삭제 후 char *에 대입
 * 		0 반환
 * 	아니면
 * 		-1 반환
 */
int
value_txt_remove(struct value *, char *, int);

/*
 * 	문자 탐색
 *
 * 	만약 int가 문자열 인덱스 범위 안에 있다면
 * 		int에 해당하는 문자를 char *에 대입
 * 		0 반환
 * 	아니면
 * 		-1 반환
 */
int
value_txt_get(struct value *, char *, int);

/*
 * 	문자열 병합
 * 	
 * 	왼쪽 문자열을 오른쪽 문자열 끝에 이어붙이기
 */
void
value_txt_append(struct value *, struct value);

/*
 * 	문자열 분할
 * 	
 * 	만약 int가 왼쪽 문자열 인덱스 범위 안에 있다면
 * 		int에 해당하는 인덱스부터 문자열 끝까지를 오른쪽 문자열 포인터에 대입
 * 		0 반환
 * 	아니면
 * 		-1 반환
 */
int
value_txt_split(struct value *, struct value *, int);

/*
 * 	배열
 *
 * 	문자열과 동일
 */

int
value_arr_push(struct value *, struct value);

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
