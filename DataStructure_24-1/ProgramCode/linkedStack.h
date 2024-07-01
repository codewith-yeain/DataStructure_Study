// 인공지능공학부, 2310165, 최예인, linkedStack.h, 2024년 5월 13일
#pragma once // 중복되는 요소를 한 번만 include 해주는 명령어
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data; // 실질적인 리스트의 요소가 저장될 공간
	struct Node* link; // 별명이 아직 붙기 전이라 앞에 struct를 꼭 붙여줘야함(아직 typedef Node가 정의되지 않은 상태)
}Node;


typedef struct LinkedStack {
	Node* top;
}LinkedStack;


// init(): 초기화 함수
void init(LinkedStack* s) {
	s->top = NULL;
}


// isEmpty()
// 스택이 비어있는지 검사하는 함수
int isEmpty(LinkedStack* s) {
	return s->top == NULL;
}

// isFull(): LinkedStack은 필요없음


// push()
void push(LinkedStack* s, char element) {
	// 새롭게 추가할 노드는 이 함수 호출이 끝나더라도 메모리에 남아있어야 한다.
	// 따라서 힙메모리에 동적할당을 해준다.
	Node* newNode = (Node*)malloc(sizeof(Node));
	// newNode 에는 새롭게 만들어진 노드가 할당된 주소가 담겨있다.
	newNode->data = element;
	newNode->link = s->top;
	s->top = newNode;
	//printf("%d노드의 주소 : %d\n", element, newNode);
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
int peek(LinkedStack* s) { // 값을 되돌려 받을 res
	if (isEmpty(s)) return 0; // 스택이 비었다면

	return s->top->data;
}