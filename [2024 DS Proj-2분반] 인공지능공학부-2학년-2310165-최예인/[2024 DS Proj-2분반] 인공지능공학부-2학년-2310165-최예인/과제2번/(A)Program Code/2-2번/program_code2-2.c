// 인공지능공학부, 2310165, 최예인, program_code2-2.c(2번문제 2번째 게임), 2024년 6월 1일
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "doubleyLinkedList.h"


void makeCircular(Dlist* list) {
    if (list->head == NULL || list->tail == NULL) return; 

    list->tail->rlink = list->head;
    list->head->llink = list->tail;
}

int len(Dlist* list) {
    int length = 0;
    Node* curr = list->head;
    if (curr == NULL) return 0;

    do {
        length++;
        curr = curr->rlink;
    } while (curr != list->head);

    return length;
}


int main() {
    Dlist list;
    init(&list);

    Person p1 = { 1, "Kim" };
    Person p2 = { 2, "Lee" };
    Person p3 = { 3, "Choi" };
    Person p4 = { 4, "Yoon" };
    Person p5 = { 5, "Park" };
    Person p6 = { 6, "Jung" };
    Person p7 = { 7, "Kang" };
    Person p8 = { 8, "Cho" };
    Person p9 = { 9, "Shin" };
    Person p10 = { 10, "Lim" };
    Person p11 = { 11, "Han" };
    Person p12 = { 12, "Oh" };
    Person p13 = { 13, "Kwon" };
    Person p14 = { 14, "Hwang" };
    Person p15 = { 15, "Son" };
    Person p16 = { 16, "Jan" };
    Person p17 = { 17, "Hong" };
    Person p18 = { 18, "Seo" };
    Person p19 = { 19, "Moon" };
    Person p20 = { 20, "Ryu" };

    insertFirst(&list, p1);
    append(&list, p2);
    append(&list, p3);
    append(&list, p4);
    append(&list, p5);
    append(&list, p6);
    append(&list, p7);
    append(&list, p8);
    append(&list, p9);
    append(&list, p10);
    append(&list, p11);
    append(&list, p12);
    append(&list, p13);
    append(&list, p14);
    append(&list, p15);
    append(&list, p16);
    append(&list, p17);
    append(&list, p18);
    append(&list, p19);
    append(&list, p20);

    srand((unsigned int)time(NULL));
    int random = rand() % 20 + 1;

    makeCircular(&list);

    Node* curr = list.head;
    for (int i = 1; i < random; i++) {
        curr = curr->rlink;
    }
    printf("처음 수건을 받은 사람: [%02d-%s]\n", curr->data.number, curr->data.name);

    int count = 1;
    while (count < 17) {
        if (count % 2 == 1) { // 홀수일 경우
            printf("\n{%d단계}\n", count);

            Node* removeNode = curr->rlink->rlink;

            printf("제거된 사람: [%02d-%s]\n", removeNode->data.number, removeNode->data.name);

            curr = removeNode->llink;
            if (curr == list.head) {
                curr = list.tail->rlink;
            }

            // 삭제
            removeNode->llink->rlink = removeNode->rlink;
            removeNode->rlink->llink = removeNode->llink;
            if (removeNode == list.head) list.head = removeNode->rlink;
            if (removeNode == list.tail) list.tail = removeNode->llink;
            free(removeNode);

            printf("남은 사람: ");
            show(&list);

            printf("\n----------\n");

            // printf("수건을 받은 사람: [%02d-%s]\n", curr->data.number, curr->data.name);
        }
        else { // 짝수일 경우
            printf("\n{%d단계}\n", count);

            Node* removeNode = curr;
            for (int i = 0; i < 7; i++) {
                removeNode = removeNode->llink;
            }

            printf("제거된 사람: [%02d-%s]\n", removeNode->data.number, removeNode->data.name);

            curr = removeNode->rlink;
            if (curr == list.tail) {
                curr = list.head->llink;
            }

            // 삭제
            removeNode->llink->rlink = removeNode->rlink;
            removeNode->rlink->llink = removeNode->llink;
            if (removeNode == list.head) list.head = removeNode->rlink;
            if (removeNode == list.tail) list.tail = removeNode->llink;
            free(removeNode);

            printf("남은 사람: ");
            show(&list);

            printf("\n----------\n");

            // printf("수건을 받은 사람: [%02d-%s]\n", curr->data.number, curr->data.name);
        }
        count++;
    }

    printf("\n행운의 최종 4명: ");
    show(&list);

    // 메모리 해제
    if (list.head != NULL) {
        Node* curr = list.head;
        Node* next;

        do {
            next = curr->rlink;
            free(curr);
            curr = next;
        } while (curr != list.head);

        list.head = NULL;
        list.tail = NULL;
    }

    return 0;
}


