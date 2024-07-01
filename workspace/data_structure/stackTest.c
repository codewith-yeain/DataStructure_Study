#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 10

typedef struct Stack {
	int ar[MAX];
	int top; // ������� �ε��� ��ȣ�� �˰� �ִ� ����
}Stack;

void init(Stack* s) {
	s->top = -1; // ��Ұ� �����Ƿ� ���� ������ -1�� �ȴ�.
}

// push(): ���ÿ� ��Ҹ� �߰��ϴ� �Լ�
void push(Stack* s, int element) {
	// ��� �ڵ�, ���� �� ���� ���
	if (s->top == MAX-1) {
		printf("������ ���� ���־� !!!!!!! \n");
		return;
	}

	s->ar[++s->top] = element;

}

// pop(): ���ÿ��� ��Ҹ� �������ִ� �Լ�, ������ ��Ҹ� return �Ѵ�.
int pop(Stack* s) {
	// ����ڵ�, ������� ���
	if (s->top == -1) {
		printf("������ ��� �־� !!!!!!! \n");
		return 0;
	}

	/*int temp = s->ar[s->top];
	s->top--;
	return temp;*/
	return s->ar[s->top--];
}


// peek(): top�� ��ġ�� ��Ҹ� ������ �Լ�
int peek(Stack* s) {
	// ����ڵ�, ������� ���
	if (s->top == -1) {
		printf("������ ��� �־� !!!!!!! \n");
		return 0;
	}

	return s->ar[s->top];
}

// clear(): ���ÿ� �ִ� ��� ��Ҹ� �������ִ� �Լ�
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

	printf("������ ���: %d\n", pop(&s));
	printf("������ ���: %d\n", pop(&s));
	printf("������ ���: %d\n", pop(&s));
	show(&s);

	printf("top�� �ִ� ���: %d\n", peek(&s));
	show(&s);

	clear(&s);
	show(&s);

	return 0;
}