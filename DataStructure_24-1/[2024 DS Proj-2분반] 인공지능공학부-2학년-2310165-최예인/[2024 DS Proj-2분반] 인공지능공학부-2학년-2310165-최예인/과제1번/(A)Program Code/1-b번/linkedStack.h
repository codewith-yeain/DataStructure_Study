// �ΰ����ɰ��к�, 2310165, �ֿ���, linkedStack.h, 2024�� 5�� 13��
#pragma once // �ߺ��Ǵ� ��Ҹ� �� ���� include ���ִ� ��ɾ�
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data; // �������� ����Ʈ�� ��Ұ� ����� ����
	struct Node* link; // ������ ���� �ٱ� ���̶� �տ� struct�� �� �ٿ������(���� typedef Node�� ���ǵ��� ���� ����)
}Node;


typedef struct LinkedStack {
	Node* top;
}LinkedStack;


// init(): �ʱ�ȭ �Լ�
void init(LinkedStack* s) {
	s->top = NULL;
}


// isEmpty()
// ������ ����ִ��� �˻��ϴ� �Լ�
int isEmpty(LinkedStack* s) {
	return s->top == NULL;
}

// isFull(): LinkedStack�� �ʿ����


// push()
void push(LinkedStack* s, char element) {
	// ���Ӱ� �߰��� ���� �� �Լ� ȣ���� �������� �޸𸮿� �����־�� �Ѵ�.
	// ���� ���޸𸮿� �����Ҵ��� ���ش�.
	Node* newNode = (Node*)malloc(sizeof(Node));
	// newNode ���� ���Ӱ� ������� ��尡 �Ҵ�� �ּҰ� ����ִ�.
	newNode->data = element;
	newNode->link = s->top;
	s->top = newNode;
	//printf("%d����� �ּ� : %d\n", element, newNode);
}

// pop()
char pop(LinkedStack* s) {
	if (isEmpty(s)) return 0;

	char e = s->top->data;
	Node* oldNode = s->top;
	s->top = s->top->link;
	free(oldNode);

	return e;
}

// delete()
int deleteNode(LinkedStack* s) {
	if (isEmpty(s)) return 0;

	Node* oldNode = s->top;
	s->top = s->top->link;
	free(oldNode);

	return 1;
}

// peek()
int peek(LinkedStack* s) { // ���� �ǵ��� ���� res
	if (isEmpty(s)) return 0; // ������ ����ٸ�

	return s->top->data;
}