// 인공지능공학부, 2310165, 최예인, singlyLinkedList.h, 2024년 5월 26일
#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct Node {
	int number;
	char name[10];
	struct Node* link;
}Node;


typedef struct LinkedList {
	Node* head;
}List;


void init(List* list) {
	list->head = NULL;
};



void show(List* list) {
	Node* curr = list->head;
	while (curr != NULL)
	{
		printf("[%02d-%s] ", curr->number, curr->name);
		curr = curr->link;
	}
	printf("\n");
}



void insertFirst(List* list, int number, const char* name) {
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->number = number;
	strncpy(newNode->name, name, sizeof(newNode->name) - 1);
	newNode->name[sizeof(newNode->name) - 1] = '\0';
	newNode->link = list->head;
	list->head = newNode;
}


void append(List* list, int number, const char* name) {
	if (list->head == NULL) {
		insertFirst(list, number, name);
		return;
	}

	Node* curr = list->head;
	while (curr->link != NULL) {
		curr = curr->link;
	}

	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->number = number;

	strncpy(newNode->name, name, sizeof(newNode->name) - 1);
	newNode->name[sizeof(newNode->name) - 1] = '\0';

	newNode->link = NULL;
	curr->link = newNode;
}
