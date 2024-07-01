#pragma once // �ߺ��Ǵ� ��Ҹ� �� ���� include ���ִ� ��ɾ�
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
	if (s->top == MAX-1) return 0; // �� �ٸ��� ���� �� �߰�ȣ ���� ����

	s->ar[++s->top] = element;
	return 1;

}

// pop()
int pop(Stack* s, char* res) { // ������ ���� �ǵ��� ���� res
	if (s->top == -1) return 0; // ������ ����ٸ�

	*res = s->ar[s->top--];
	return 1;
}

// peek()
int peek(Stack* s, char* res) { // ������ ���� �ǵ��� ���� res
	if (s->top == -1) return 0; // ������ ����ٸ�

	*res = s->ar[s->top];
	return 1;
}

// clear()
void clear(Stack* s) {
	s->top = -1;
}

// isEmpty()
// ������ ����ִ��� �˻��ϴ� �Լ�
int isEmpty(Stack* s) {
	return s->top == -1;
}

// isFull()
// ������ ���� á���� �˻��ϴ� �Լ�
int isFull(Stack* s) {
	return s->top == MAX - 1;
}