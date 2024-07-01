// �ΰ����ɰ��к�, 2310165, �ֿ���, program_code2-1.c(2������ 1��° ����), 2024�� 5�� 26��

#define _CRT_SECURE_NO_WARNINGS
#include "singlyLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void makeCircular(List* list) {
    if (list->head == NULL) return;
    Node* curr = list->head;
    while (curr->link != NULL) {
        curr = curr->link;
    }
    curr->link = list->head;
}

int lenCircular(List* list) {
    if (list->head == NULL) return 0;
    Node* curr = list->head;
    int length = 1;
    while (curr->link != list->head) {
        length++;
        curr = curr->link;
    }
    return length;
}

int main() {
    List list;
    init(&list);
    insertFirst(&list, 1, "Kim");
    append(&list, 2, "Lee");
    append(&list, 3, "Choi");
    append(&list, 4, "Yoon");
    append(&list, 5, "Park");
    append(&list, 6, "Jung");
    append(&list, 7, "Kang");
    append(&list, 8, "Cho");
    append(&list, 9, "Shin");
    append(&list, 10, "Lim");
    append(&list, 11, "Han");
    append(&list, 12, "Oh");
    append(&list, 13, "Kwon");
    append(&list, 14, "Hwang");
    append(&list, 15, "Son");
    append(&list, 16, "Jan");
    append(&list, 17, "Hong");
    append(&list, 18, "Seo");
    append(&list, 19, "Moon");
    append(&list, 20, "Ryu");

    srand(time(NULL));
    int random = rand() % 20 + 1;

    makeCircular(&list);

    Node* curr = list.head;
    for (int i = 1; i < random; i++) {
        curr = curr->link;
    }
    printf("ó�� ������ ���� ���: [%02d-%s]\n\n", curr->number, curr->name);
    
    int length = lenCircular(&list);
    printf("{%d�ܰ�}\n ", 21 - length);

    Node* removeNode = curr->link->link;
    printf("���ŵ� ���: [%02d-%s]\n", removeNode->number, removeNode->name);

    curr->link->link = removeNode->link; 
    if (removeNode == list.head) {
        list.head = removeNode->link;
    }
    free(removeNode);
    
    Node* temp = curr->link->link;
    
    printf("���� ���: ");
    length = lenCircular(&list);
    for (int i = 0; i < length; i++) {
        printf("[%02d-%s] ", temp->number, temp->name);
        temp = temp->link;
    }

    curr = curr->link->link->link;

    printf("\n\n----------\n\n");


    // �� ��° �ܰ���� �ݺ�

    while (lenCircular(&list) > 4) {
        int length = lenCircular(&list);
        printf("{%d�ܰ�}\n ", 21 - length);
        Node* removeNode = curr->link;
        printf("���ŵ� ���: [%02d-%s]\n", removeNode->number, removeNode->name);

        curr->link = removeNode->link;
        if (removeNode == list.head) {
            list.head = removeNode->link;
        }
        free(removeNode);

        Node* temp = curr->link;

        printf("���� ���: ", length);
        for (int i = 0; i < length; i++) {
            printf("[%02d-%s] ", temp->number, temp->name);
            temp = temp->link;
        }
        
        curr = curr->link->link;

        printf("\n\n----------\n\n");
    }

    // ��ȯ ����Ʈ�� �Ϲ� ����Ʈ�� ��ȯ
    if (list.head != NULL) {
        Node* temp = list.head;
        while (temp->link != list.head) {
            temp = temp->link;
        }
        temp->link = NULL;
    }

    printf("����� ���� 4��: ");
    show(&list);

    return 0;
}
