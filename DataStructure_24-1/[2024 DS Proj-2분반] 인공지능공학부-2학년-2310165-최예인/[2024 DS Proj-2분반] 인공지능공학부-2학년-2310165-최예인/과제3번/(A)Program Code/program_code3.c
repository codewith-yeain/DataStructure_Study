// �ΰ����ɰ��к�, 2310165, �ֿ���, program_code3.c(���� ����Ʈ ���� �˻�), 2024�� 6�� 1��
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linkedList.h"

int main() {
    struct Node* head = NULL;
    struct Node* sortedList = NULL;
    int value;
    int searchTargets[10] = { 3, 97, 96, 111, 15, 9, 66, 120, 99, 59 };

    // ����
    printf("[ 31���� ���� ������� �Է��ϼ��� ]\n");

    for (int i = 0; i < 31; i++) {
        scanf_s("%d", &value);
        appendNode(&head, value);
    }
    printf("31�� �Է� �Ϸ� !\n");

    printf("\n���� ��: ");
    printList(head);

    sortedList = selectionSort(head);

    printf("���� ��: ");
    printList(sortedList);

    printf("\n[ �˻� ��� ]\n");

    // ����Ž��
    for (int i = 0; i < 10; i++) {
        int target = searchTargets[i];
        int index = binarySearch(sortedList, target);

        if (index != -1) {
            printf("(%d) �� %d [True] (��� ��ġ: %d��°)\n", i + 1, target, index + 1);
        }
        else {
            printf("(%d) �� %d [False] (No Result in List)\n", i + 1, target);
        }
    }

    return 0;
}
