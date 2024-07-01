#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 5

typedef struct {
    int ar[MAX]; // 실질적 크기
    int length; // 요소의 갯수
}ArrayList;




// 구조체 멤버변수는 정의와 동시에 초기화가 불가능 하기 때문에
// 초기화 할 수 있는 함수를 정의하자.
void init(ArrayList* list) {
    list->length = 0;
}

// 리스트의 요소 확인용 함수 만들기
void show(ArrayList* list) {
    if (list->length == 0) {
        printf("현재 예약 인원이 없습니다.\n");
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

// 추가
// 맨 뒤에 추가
int append(ArrayList* list, int element) {
    if (isFull(list)) {
        return 0; // 함수 종료를 의미하기도 한다.
    }
    // length는 index보다 1 더 크다.
    list->ar[list->length++] = element;
    return 1;
}

// 삽입
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

// 삭제
// 인덱스 번호로 삭제하기
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

// 요소로 삭제하기
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

// 같은 요소 모두 삭제하기
void removeElements(ArrayList* list, int element) {
    while (removeElement(list, element));
}

// 수정
// 인덱스 번호로 수정하기
int updateByIdx(ArrayList* list, int idx, int element) {
    if (idx >= list->length) { // 방어 코드
        return 0;
    }
    list->ar[idx] = element;
    return 1;
}

// 요소 값으로 수정하기
// data -> 수정하고 싶은 값
// source -> 요걸로 수정할래요
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

// 검색
int select(ArrayList* list, int idx) {
    if (idx >= list->length || idx < 0) {
        return 0;
    }
    return list->ar[idx];
}

// 예약 시스템 실습 함수
// 내 앞에 몇 명의 대기자가 있는지 구하는 함수
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
    //printf("1번째 방에 들어있는 값 : %d\n", select(&list, 1));

    // 예약 서비스 프로그램 제작 실습
    int choice;
    int phone;
    ArrayList users;
    ArrayList* ptr = &users;
    init(ptr);

    while (1) {
        printf("=====예약 정보 시스템=====\n");
        printf("1. 현재 예약 정보 확인하기\n");
        printf("2. 예약하기\n");
        printf("3. 예약 취소 하기\n");
        printf("4. 내 예약 정보보기\n");
        printf("5. 프로그램 종료하기\n");
        printf("메뉴를 선택하세요 >> ");
        scanf("%d", &choice);

        if (choice == 5) {
            printf("프로그램을 종료합니다.");
            break;
        }
        else if (choice == 1) {
            show(ptr);
        }
        else if (choice == 2) {
            if (isFull(ptr)) {
                printf("현재 예약 인원 가득 찼습니다. 잠시만 기다려주세요.\n");
                continue;
            }
            printf("휴대폰 번호 뒤 네자리를 입력해주세요 >> ");
            scanf("%d", &phone);
            append(ptr, phone);
            printf("예약 성공, 당신의 대기번호는 %d번 입니다.\n", ptr->length);
        }
        else if (choice == 3) {
            printf("예약 취소 휴대폰 번호 뒤 네자리를 입력하세요 >> ");
            scanf("%d", &phone);
            if (removeElement(ptr, phone)) {
                printf("예약 취소 됐습니다!\n");
            }
            else {
                printf("해당 번호가 존재하지 않습니다.\n");
            }
        }
        else if (choice == 4) {
            printf("번호 입력 >> ");
            scanf("%d", &phone);

            if (indexOf(ptr, phone) == -1) {
                printf("번호를 다시 한 번 확인해주세요.\n");
                continue;
            }
            printf("예약 번호 : %d\n", phone);
            printf("%d 명이 앞에 대기자로 있습니다.\n", indexOf(ptr, phone));
        }
        else {
            printf("다시 입력해주세요\n");
        }
    }

    return 0;
}