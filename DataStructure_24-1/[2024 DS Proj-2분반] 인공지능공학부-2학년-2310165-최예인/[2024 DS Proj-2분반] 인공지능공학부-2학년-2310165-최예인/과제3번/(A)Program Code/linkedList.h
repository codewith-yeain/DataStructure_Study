// 인공지능공학부, 2310165, 최예인, linkedList.h, 2024년 6월 1일
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 리스트에 노드를 추가하는 함수
void appendNode(struct Node** headRef, int newData) {
    struct Node* new_node = createNode(newData);
    struct Node* last = *headRef;

    if (*headRef == NULL) {
        *headRef = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

// 리스트에서 최소값의 노드를 찾고 그 노드를 리스트에서 제거하는 함수
struct Node* removeMinNode(struct Node** headRef) {
    struct Node* temp = *headRef;
    struct Node* minNode = temp;
    struct Node* prevMin = NULL;
    struct Node* prev = NULL;

    // 최소값 노드를 찾기
    while (temp != NULL) {
        if (temp->data < minNode->data) {
            minNode = temp;
            prevMin = prev;
        }
        prev = temp;
        temp = temp->next;
    }

    // 최소값 노드를 리스트에서 제거
    if (prevMin == NULL) { *headRef = minNode->next;}
    else { prevMin->next = minNode->next; }

    return minNode;
}

// 선택 정렬을 사용하여 새로운 링크드 리스트에 정렬된 노드들을 추가하는 함수
struct Node* selectionSort(struct Node* head) {
    struct Node* sortedList = NULL;
    struct Node* minNode;

    while (head != NULL) {
        minNode = removeMinNode(&head);
        appendNode(&sortedList, minNode->data);
        free(minNode);
    }

    return sortedList;
}

// 리스트를 출력하는 함수
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// 리스트의 길이를 계산하는 함수
int listLength(struct Node* head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

// 주어진 인덱스에 있는 노드를 찾는 함수
struct Node* getNodeFromIndex(struct Node* head, int index) {
    struct Node* current = head;
    for (int i = 0; i < index && current != NULL; i++) {
        current = current->next;
    }
    return current;
}

// 이진 탐색 함수 (index를 반환)
int binarySearch(struct Node* head, int target) {
    int left = 0;
    int right = listLength(head) - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        struct Node* midNode = getNodeFromIndex(head, mid);

        if (midNode == NULL) { return -1; }

        if (midNode->data == target) { return mid; }
        else if (midNode->data < target) { left = mid + 1; }
        else { right = mid - 1; }
    }
    return -1;
}
