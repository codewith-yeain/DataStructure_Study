#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 10

typedef struct Stack {
	int ar[MAX];
	int top; // 꼭대기의 인덱스 번호를 알고 있는 변수
}Stack;

void init(Stack* s) {
	s->top = -1; // 요소가 없으므로 현재 꼭대기는 -1이 된다.
}

// push(): 스택에 요소를 추가하는 함수
void push(Stack* s, int element) {
	// 방어 코드, 가득 차 있을 경우
	if (s->top == MAX-1) {
		printf("스택이 가득 차있어 !!!!!!! \n");
		return;
	}

	s->ar[++s->top] = element;

}

// pop(): 스택에서 요소를 삭제해주는 함수, 삭제된 요소를 return 한다.
int pop(Stack* s) {
	// 방어코드, 비어있을 경우
	if (s->top == -1) {
		printf("스택이 비어 있어 !!!!!!! \n");
		return 0;
	}

	/*int temp = s->ar[s->top];
	s->top--;
	return temp;*/
	return s->ar[s->top--];
}


// peek(): top에 위치한 요소를 엿보는 함수
int peek(Stack* s) {
	// 방어코드, 비어있을 경우
	if (s->top == -1) {
		printf("스택이 비어 있어 !!!!!!! \n");
		return 0;
	}

	return s->ar[s->top];
}

// clear(): 스택에 있는 모든 요소를 삭제해주는 함수
void clear(Stack* s) {
	s->top = -1;

}


void show(Stack* s){
	printf("-----------------------------------\n");

	for (int i = 0; i <= s->top ; i++) {
		printf("| %d ", s->ar[i]);
	}

	printf("\n-----------------------------------\n");
}


int main() {
	Stack s;
	init(&s);
	push(&s, 10);
	push(&s, 20);
	push(&s, 30);
	push(&s, 40);
	push(&s, 50);
	show(&s);

	printf("삭제된 요소: %d\n", pop(&s));
	printf("삭제된 요소: %d\n", pop(&s));
	printf("삭제된 요소: %d\n", pop(&s));
	show(&s);

	printf("top에 있는 요소: %d\n", peek(&s));
	show(&s);

	clear(&s);
	show(&s);

	return 0;
}