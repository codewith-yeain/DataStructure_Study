// �ΰ����ɰ��к�, 2310165, �ֿ���, linkedList.h, 2024�� 6�� 1��
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

// ����Ʈ�� ��带 �߰��ϴ� �Լ�
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

// ����Ʈ���� �ּҰ��� ��带 ã�� �� ��带 ����Ʈ���� �����ϴ� �Լ�
struct Node* removeMinNode(struct Node** headRef) {
    struct Node* temp = *headRef;
    struct Node* minNode = temp;
    struct Node* prevMin = NULL;
    struct Node* prev = NULL;

    // �ּҰ� ��带 ã��
    while (temp != NULL) {
        if (temp->data < minNode->data) {
            minNode = temp;
            prevMin = prev;
        }
        prev = temp;
        temp = temp->next;
    }

    // �ּҰ� ��带 ����Ʈ���� ����
    if (prevMin == NULL) { *headRef = minNode->next;}
    else { prevMin->next = minNode->next; }

    return minNode;
}

// ���� ������ ����Ͽ� ���ο� ��ũ�� ����Ʈ�� ���ĵ� ������ �߰��ϴ� �Լ�
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

// ����Ʈ�� ����ϴ� �Լ�
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// ����Ʈ�� ���̸� ����ϴ� �Լ�
int listLength(struct Node* head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

// �־��� �ε����� �ִ� ��带 ã�� �Լ�
struct Node* getNodeFromIndex(struct Node* head, int index) {
    struct Node* current = head;
    for (int i = 0; i < index && current != NULL; i++) {
        current = current->next;
    }
    return current;
}

// ���� Ž�� �Լ� (index�� ��ȯ)
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
