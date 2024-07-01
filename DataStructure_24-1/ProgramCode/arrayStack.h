// �ΰ����ɰ��к�, 2310165, �ֿ���, arrayStack.h, 2024�� 5�� 12��
#pragma once // �ߺ��Ǵ� ��Ҹ� �� ���� include ���ִ� ��ɾ�
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100

typedef struct ArrayStack {
    char* item[MAX];
    int top;
} ArrayStack;

// init(): �ʱ�ȭ �Լ�
void init(ArrayStack* s) {
    s->top = -1;
}

// isEmpty(): ������ ����ִ��� �˻��ϴ� �Լ�
int isEmpty(ArrayStack* s) {
    return s->top <= -1;
}

// isFull(): ������ ���� á���� �˻��ϴ� �Լ�
int isFull(ArrayStack* s) {
    return s->top >= (MAX - 1) && s->top >= 0;
}

// push(): ���ÿ� ��Ҹ� �߰��ϴ� �Լ�
int push(ArrayStack* s, char* element) {
    if (isFull(s)) return 0; // ������ ���� á���� ����
    s->item[++(s->top)] = element; // ���ڿ��� �����Ͽ� ����
    return 1;
}

// ���ÿ��� ��Ҹ� �����ϰ� ��ȯ�ϴ� �Լ�
char* pop(ArrayStack* s) {
    if (s->top == -1) return NULL;
    char* item = s->item[s->top];
    s->item[s->top--] = NULL; // ������ �׸��� NULL�� ����
    return item;
}


// deleteItem(): ���ÿ��� ��Ҹ� �����ϴ� �Լ�
int deleteItem(ArrayStack* s) {
    if (isEmpty(s)) return 0; // ������ ��� ������ ����
    s->top--;
    return 1;
}

// peek(): ������ �ֻ��� ��Ҹ� ��ȯ�ϴ� �Լ�
char* peek(ArrayStack* s) {
    if (isEmpty(s)) return NULL; // ������ ��� ������ ����
    return s->item[s->top];
}

// show(): ���� Ȯ�ο� �Լ�
void show(ArrayStack* s) {
    if (isEmpty(s)) {
        printf("���� ������ ����ֽ��ϴ�.\n");
        return;
    }
    for (int i = 0; i <= s->top; i++) {
        printf("[%s] ", s->item[i]);
    }
    printf("\n");
}



