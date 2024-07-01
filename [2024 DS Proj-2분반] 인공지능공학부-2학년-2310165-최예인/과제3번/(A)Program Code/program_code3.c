// 인공지능공학부, 2310165, 최예인, program_code3.c(연결 리스트 정렬 검색), 2024년 6월 1일
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linkedList.h"

int main() {
    struct Node* head = NULL;
    struct Node* sortedList = NULL;
    int value;
    int searchTargets[10] = { 3, 97, 96, 111, 15, 9, 66, 120, 99, 59 };

    // 정렬
    printf("[ 31개의 값을 순서대로 입력하세요 ]\n");

    for (int i = 0; i < 31; i++) {
        scanf_s("%d", &value);
        appendNode(&head, value);
    }
    printf("31개 입력 완료 !\n");

    printf("\n정렬 전: ");
    printList(head);

    sortedList = selectionSort(head);

    printf("정렬 후: ");
    printList(sortedList);

    printf("\n[ 검색 결과 ]\n");

    // 이진탐색
    for (int i = 0; i < 10; i++) {
        int target = searchTargets[i];
        int index = binarySearch(sortedList, target);

        if (index != -1) {
            printf("(%d) 값 %d [True] (노드 위치: %d번째)\n", i + 1, target, index + 1);
        }
        else {
            printf("(%d) 값 %d [False] (No Result in List)\n", i + 1, target);
        }
    }

    return 0;
}
