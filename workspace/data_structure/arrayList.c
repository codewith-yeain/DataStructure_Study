#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 5

typedef struct {
    int ar[MAX]; // ������ ũ��
    int length; // ����� ����
}ArrayList;




// ����ü ��������� ���ǿ� ���ÿ� �ʱ�ȭ�� �Ұ��� �ϱ� ������
// �ʱ�ȭ �� �� �ִ� �Լ��� ��������.
void init(ArrayList* list) {
    list->length = 0;
}

// ����Ʈ�� ��� Ȯ�ο� �Լ� �����
void show(ArrayList* list) {
    if (list->length == 0) {
        printf("���� ���� �ο��� �����ϴ�.\n");
    }
    for (int i = 0; i < list->length; i++) {
        printf("[%d]", list->ar[i]);
    }
    printf("\n");
}

int isFull(ArrayList* list) {
    if (list->length >= MAX) {
        return 1;
    }
    return 0;
}

// �߰�
// �� �ڿ� �߰�
int append(ArrayList* list, int element) {
    if (isFull(list)) {
        return 0; // �Լ� ���Ḧ �ǹ��ϱ⵵ �Ѵ�.
    }
    // length�� index���� 1 �� ũ��.
    list->ar[list->length++] = element;
    return 1;
}

// ����
int insert(ArrayList* list, int element, int idx) {
    if (isFull(list) || idx >= list->length) {
        return 0;
    }
    for (int i = list->length; i > idx; i--) {
        list->ar[i] = list->ar[i - 1];
    }
    list->ar[idx] = element;
    list->length++;
    return 1;
}

// ����
// �ε��� ��ȣ�� �����ϱ�
int removeByIdx(ArrayList* list, int idx) {
    if (idx >= list->length) {
        return 0;
    }

    for (int i = idx; i < list->length; i++) {
        list->ar[i] = list->ar[i + 1];
    }
    list->length--;
    return 1;
}

// ��ҷ� �����ϱ�
int removeElement(ArrayList* list, int element) {
    int flag = 0;
    int idx = 0;
    for (int i = 0; i < list->length; i++) {
        if (list->ar[i] == element) {
            flag = 1;
            idx = i;
            break;
        }
    }
    if (flag) {
        removeByIdx(list, idx);
    }
    return flag;
}

// ���� ��� ��� �����ϱ�
void removeElements(ArrayList* list, int element) {
    while (removeElement(list, element));
}

// ����
// �ε��� ��ȣ�� �����ϱ�
int updateByIdx(ArrayList* list, int idx, int element) {
    if (idx >= list->length) { // ��� �ڵ�
        return 0;
    }
    list->ar[idx] = element;
    return 1;
}

// ��� ������ �����ϱ�
// data -> �����ϰ� ���� ��
// source -> ��ɷ� �����ҷ���
void updateByElement(ArrayList* list, int data, int source) {
    int idx = 0;
    for (int i = 0; i < list->length; i++) {
        if (list->ar[i] == data) {
            idx = i;
            break;
        }
    }
    updateByIdx(list, idx, source);
}

// �˻�
int select(ArrayList* list, int idx) {
    if (idx >= list->length || idx < 0) {
        return 0;
    }
    return list->ar[idx];
}

// ���� �ý��� �ǽ� �Լ�
// �� �տ� �� ���� ����ڰ� �ִ��� ���ϴ� �Լ�
int indexOf(ArrayList* list, int element) {
    for (int i = 0; i < list->length; i++) {
        if (list->ar[i] == element) {
            return i;
        }
    }
    return -1;
}



int main() {
    //ArrayList list;
    //init(&list);
    ////printf("length : %d\n", list.length);
    ///*list.length = 0;
    //printf("length : %d\n", list.length);*/
    //append(&list, 10);
    //append(&list, 20);
    //append(&list, 30);
    //insert(&list, 5, 1);
    //removeByIdx(&list, 1);
    //updateByIdx(&list, 2, 49);
    //show(&list);
    //removeElement(&list, 20);
    //show(&list);
    //updateByElement(&list, 49, 94);
    //show(&list);
    //append(&list, 30);
    //append(&list, 30);
    //show(&list);
    //removeElements(&list, 30);
    //show(&list);
    //printf("1��° �濡 ����ִ� �� : %d\n", select(&list, 1));

    // ���� ���� ���α׷� ���� �ǽ�
    int choice;
    int phone;
    ArrayList users;
    ArrayList* ptr = &users;
    init(ptr);

    while (1) {
        printf("=====���� ���� �ý���=====\n");
        printf("1. ���� ���� ���� Ȯ���ϱ�\n");
        printf("2. �����ϱ�\n");
        printf("3. ���� ��� �ϱ�\n");
        printf("4. �� ���� ��������\n");
        printf("5. ���α׷� �����ϱ�\n");
        printf("�޴��� �����ϼ��� >> ");
        scanf("%d", &choice);

        if (choice == 5) {
            printf("���α׷��� �����մϴ�.");
            break;
        }
        else if (choice == 1) {
            show(ptr);
        }
        else if (choice == 2) {
            if (isFull(ptr)) {
                printf("���� ���� �ο� ���� á���ϴ�. ��ø� ��ٷ��ּ���.\n");
                continue;
            }
            printf("�޴��� ��ȣ �� ���ڸ��� �Է����ּ��� >> ");
            scanf("%d", &phone);
            append(ptr, phone);
            printf("���� ����, ����� ����ȣ�� %d�� �Դϴ�.\n", ptr->length);
        }
        else if (choice == 3) {
            printf("���� ��� �޴��� ��ȣ �� ���ڸ��� �Է��ϼ��� >> ");
            scanf("%d", &phone);
            if (removeElement(ptr, phone)) {
                printf("���� ��� �ƽ��ϴ�!\n");
            }
            else {
                printf("�ش� ��ȣ�� �������� �ʽ��ϴ�.\n");
            }
        }
        else if (choice == 4) {
            printf("��ȣ �Է� >> ");
            scanf("%d", &phone);

            if (indexOf(ptr, phone) == -1) {
                printf("��ȣ�� �ٽ� �� �� Ȯ�����ּ���.\n");
                continue;
            }
            printf("���� ��ȣ : %d\n", phone);
            printf("%d ���� �տ� ����ڷ� �ֽ��ϴ�.\n", indexOf(ptr, phone));
        }
        else {
            printf("�ٽ� �Է����ּ���\n");
        }
    }

    return 0;
}