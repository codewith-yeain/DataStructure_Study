// 인공지능공학부, 2310165, 최예인, arrayStack.h, 2024년 5월 12일
#pragma once // 중복되는 요소를 한 번만 include 해주는 명령어
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100

typedef struct ArrayStack {
    char* item[MAX];
    int top;
} ArrayStack;

// init(): 초기화 함수
void init(ArrayStack* s) {
    s->top = -1;
}

// isEmpty(): 스택이 비어있는지 검사하는 함수
int isEmpty(ArrayStack* s) {
    return s->top <= -1;
}

// isFull(): 스택이 가득 찼는지 검사하는 함수
int isFull(ArrayStack* s) {
    return s->top >= (MAX - 1) && s->top >= 0;
}

// push(): 스택에 요소를 추가하는 함수
int push(ArrayStack* s, char* element) {
    if (isFull(s)) return 0; // 스택이 가득 찼으면 실패
    s->item[++(s->top)] = element; // 문자열을 복사하여 저장
    return 1;
}

// 스택에서 요소를 제거하고 반환하는 함수
char* pop(ArrayStack* s) {
    if (s->top == -1) return NULL;
    char* item = s->item[s->top];
    s->item[s->top--] = NULL; // 해제된 항목을 NULL로 설정
    return item;
}


// deleteItem(): 스택에서 요소를 제거하는 함수
int deleteItem(ArrayStack* s) {
    if (isEmpty(s)) return 0; // 스택이 비어 있으면 실패
    s->top--;
    return 1;
}

// peek(): 스택의 최상위 요소를 반환하는 함수
char* peek(ArrayStack* s) {
    if (isEmpty(s)) return NULL; // 스택이 비어 있으면 실패
    return s->item[s->top];
}

// show(): 스택 확인용 함수
void show(ArrayStack* s) {
    if (isEmpty(s)) {
        printf("현재 스택이 비어있습니다.\n");
        return;
    }
    for (int i = 0; i <= s->top; i++) {
        printf("[%s] ", s->item[i]);
    }
    printf("\n");
}



