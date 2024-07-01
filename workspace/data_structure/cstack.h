#pragma once // 중복되는 요소를 한 번만 include 해주는 명령어
#include <stdio.h>
#define MAX 10

typedef struct CharStack {
	char ar[MAX];
	int top;
}Stack;

void init(Stack* s) {
	s->top = -1;
}


// push()
int push(Stack* s, char element) {
	if (s->top == MAX-1) return 0; // 한 줄만에 끝날 때 중괄호 생략 가능

	s->ar[++s->top] = element;
	return 1;

}

// pop()
int pop(Stack* s, char* res) { // 삭제된 값을 되돌려 받을 res
	if (s->top == -1) return 0; // 스택이 비었다면

	*res = s->ar[s->top--];
	return 1;
}

// peek()
int peek(Stack* s, char* res) { // 삭제된 값을 되돌려 받을 res
	if (s->top == -1) return 0; // 스택이 비었다면

	*res = s->ar[s->top];
	return 1;
}

// clear()
void clear(Stack* s) {
	s->top = -1;
}

// isEmpty()
// 스택이 비어있는지 검사하는 함수
int isEmpty(Stack* s) {
	return s->top == -1;
}

// isFull()
// 스택이 가득 찼는지 검사하는 함수
int isFull(Stack* s) {
	return s->top == MAX - 1;
}