// �ΰ����ɰ��к�, 2310165, �ֿ���, doubleyLinkedList.h, 2024�� 5�� 27��
#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct Person {
    int number;
    char name[50];
} Person;

typedef struct Node {
    Person data;
    struct Node* llink;
    struct Node* rlink;
} Node;

typedef struct Dlist{
    Node* head;
    Node* tail;
} Dlist;


void init(Dlist* list) {
    list->head = NULL;
    list->tail = NULL;
}

void insertFirst(Dlist* list, Person data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "�޸� �Ҵ� ����\n");
        exit(1);
    }

    newNode->data = data;
    newNode->llink = NULL;
    newNode->rlink = list->head;

    if (list->head != NULL) {
        list->head->llink = newNode;
    }
    else {
        list->tail = newNode;
    }
    list->head = newNode;
}

void append(Dlist* list, Person data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "�޸� �Ҵ� ����\n");
        exit(1);
    }

    newNode->data = data;
    newNode->rlink = NULL;
    newNode->llink = list->tail;

    if (list->tail != NULL) {
        list->tail->rlink = newNode;
    }
    else {
        list->head = newNode;
    }
    list->tail = newNode;
}

void show(Dlist* list) {
    Node* curr = list->head;
    while (curr != NULL) {
        printf("[%02d-%s] ", curr->data.number, curr->data.name);
        curr = curr->rlink;
        if (curr == list->head) break; // ��ȯ ����Ʈ�� ��� ����
    }
    printf("\n");
}

