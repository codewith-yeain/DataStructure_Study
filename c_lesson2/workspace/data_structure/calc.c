#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h> // 동적할당 위한 헤더파일
#include "cstack.h" // 사용자가 정의한 헤더파일을 사용할 경우 ""를 사용한다.

// 연산자의 우선순위를 알려주는 함수
int prec(char op) {
	switch (op) {
	case'+':
	case'-':
		return 0;
	case '*':
	case '/':
		return 1;
	}
	return -1;
}


// 중위 표현식을 후위 표현식으로 바꾸는 함수
char* inToPost(char exp[]) {// exp: 사용자가 입력한 중위표현식
	// res: 후위 표현식으로 바꾼 결과를 저장할 배열
	char* res = (char*)malloc(sizeof(char) * 100);
	int idx = 0; // res의 인덱스 번호
	int length = strlen(exp);
	char top; // 스택의 top에 들어있는 요소를 담아줄 변수
	Stack s; // 잠시 사용할 스택

	init(&s);

	for (int i = 0; i < length; i++) {
		char ch = exp[i]; // ch: 중위표현식 속 문자 하나

		if (ch >= '0' && ch <= '9') { // 숫자라면
			res[idx++] = ch; // 그대로 res에 담아준다.
		}
		else if(ch == '+' || ch == '-' || ch == '*' || ch == '/') {
			// 만약 연산자라면
			peek(&s, &top);
			// 스택이 비어있지 않고, 
			// 지금 넣고자 하는 연산자가 스택에 존재하는 연산자보다 우선 순위가 작거나 같다면
			while (!isEmpty(&s) && prec(ch) <= prec(top)) {
				pop(&s, &top); // 스택에 있는 연산자를 꺼내서
				res[idx++] = top; // res에 담아주고
				peek(&s, &top); // 스택에 존재하는 다음 연사자를 top에 담아준다.
			}
			push(&s, ch);
		}
		//else if (ch == '('){ // 여는 소괄호라면
		//	// 무조건 스택에 푸시한다.
		//	push(&s, ch);
		//}
		//else if (ch == ')') { // 닫는 소괄호라면
		//	// top이 '('가 될 때까지 뽑아서 res에 붙여준다.
		//	pop(&s, &top);
		//	while (top != '(') {
		//		res[idx++] = top;
		//		pop(&s, &top);
		//	}
		//}
	}// for

	while (!isEmpty(&s)) {
		pop(&s, &top);
		res[idx++] = top;
	}

	res[idx] = '\0';
	return res;

}// while

int main() {

	printf("수식 입력 : ");
	char exp[100];
	scanf("%s", exp);
	char* res = inToPost(exp);
	printf("후위표현식으로 바뀐 식 : %s\n", res);


	return 0;
}