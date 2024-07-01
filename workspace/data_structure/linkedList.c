#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data; // 실질적인 리스트의 요소가 저장될 공간
	struct Node* link; // 별명이 아직 붙기 전이라 앞에 struct를 꼭 붙여줘야함(아직 typedef Node가 정의되지 않은 상태)
}Node;

typedef struct LinkedList {
	Node* head; // 제일 첫 번째 시작 노드의 주소를 담는 역할을 할 뿐이다.
}List;


// 초기화 함수
void init(List* list) {
	list->head = NULL;
};

// 요소 확인용 show 함수
void show(List* list) {
	// 순회용 포인터
	Node* curr = list->head; // curr에는 첫 번째 노드를 담아준다.
	while (curr != NULL)
	{
		printf("[%d]->", curr->data);
		curr = curr->link;
	}
	printf("\n");
}

// 추가
// 맨 앞에 추가하기
// List에 데이터를 처음 추가할 때 사용할 함수

void insertFirst(List* list, int element) {
	// 새롭게 추가할 노드는 이 함수 호출이 끝나더라도 메모리에 남아있어야 한다.
	// 따라서 힙메모리에 동적할당을 해준다.
	Node* newNode = (Node*)malloc(sizeof(Node));
	// newNode 에는 새롭게 만들어진 노드가 할당된 주소가 담겨있다.
	newNode->data = element;
	newNode->link = list->head;
	list->head = newNode;
	//printf("%d노드의 주소 : %d\n", element, newNode);
}

// 데이터 추가
void append(List* list, int element) {
	// 리스트에 요소가 하나도 없다면
	if (list->head == NULL) {
		insertFirst(list, element); // 맨 처음에 요소를 추가한다.
		return; // 함수 종료의 의미로 사용
	}

	Node* curr = list->head;
	while (curr->link != NULL) {
		curr = curr->link;
	}
	// 반복문을 다 돌고나면 curr에는 마지막 노드가 담겨있다.
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = element;
	newNode->link = NULL;
	curr->link = newNode;
}

// 리스트 요소의 갯수를 알려주는 함수
int len(List* list) {

	if (list->head == NULL) {
		return 0;
	}

	Node* curr = list->head;
	int length = 0;
	while (curr != NULL) {
		length++;
		curr = curr->link;
	}
	// 반복문이 다 끝나게 된다면 length에는 리스트 요소의 갯수가 담기게 된다.
	return length;
}


// 데이터를 중간에 추가하기
// 인덱스 번호를 활용하여 추가하기
void insert(List* list, int idx, int element) {

	// 인덱스 번호가 음수이거나 길이보다 클 경우
	if (idx < 0 || idx > len(list)) {
		printf("ERROR: 인덱스 범위 오류\n");
		return;
	}

	// 삽입하고자 하는 idx가 0번일 경우
	if (idx == 0) {
		insertFirst(list, element);
		return;
	}

	Node* curr = list->head;

	// 여기서는 idx 값으로 반복 횟수를 확정할 수 있기 때문에 while이 아닌 for 사용
	for (int i = 0; i < idx - 1; i++) {
		curr = curr->link;
	}
	// 반복문을 다 돌고 나오면 curr에는 내가 삽입할 이전 노드가 들어있다.
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = element;

	// 아래의 코드가 순서가 바뀌면 절대 안됨
	newNode->link = curr->link;
	curr->link = newNode;
}

// 삭제
// 맨 앞의 요소 삭제
void removeFirst(List* list) {
	// 리스트가 비어있다면
	if (list->head == NULL) {
		printf("데이터가 아무것도 없습니다.");
		return;
	}

	
	// 우리가 삭제할 노드는 head에 담겨있는 주소이다.
	// 하지만, 그 주소를 바로 삭제해버린다면, 링크드리스트의 시작 주소를 잃어버리는 것이기에
	// 삭제하기 전에 head에 두 번째 노드의 주소를 담아줘야 한다.
	// 그렇게 된다면, 내가 동적할당 해제 하고 싶은 주소를 잃어버리기 때문에,
	// 그 전에 포인터를 하나 만들어서, 내가 삭제하고 싶은 노드의 주소를 담아 놓는다.
	// [나의 이해] 첫 번째 노드가 될 예정인 노드의 주소를 찾기 위해 삭제할 노드를 담는다.

	Node* removeNode = list->head; // 삭제할 노드
	list->head = removeNode->link; // head에 첫 번째 노드가 될 예정인 노드의 주소를 담는다.
	free(removeNode); // 첫 번째 노드를 삭제한다.
}

// 마지막 요소 삭제하기
void removeLast(List* list) {
	// 리스트가 비어있다면
	if (list->head == NULL) {
		printf("데이터가 아무것도 없습니다.");
		return;
	}

	if (len(list) == 1) {
		removeFirst(list);
		return;
	}
	// 리스트 요소가 한 개 들어있을 경우
	// curr->link가 NULL이기 떄문에
	// curr->link->link는 사실상 NULL->link를 의미하게 된다.
	// 따라서 오류가 발생한다.
	Node* curr = list->head;

	while (curr->link->link != NULL) {
		curr = curr->link;
	}
	// 반복이 끝나면 curr에는 마지막 이전 노드가 들어있다.
	free(curr->link);
	curr->link = NULL;
}

// 인덱스 번호로 삭제하기
void removeByIdx(List* list, int idx) {
	if (idx < 0 || idx > len(list)-1) {
		printf("ERROR: 인덱스 범위 오류\n");
		return;
	}

	// 0번째 요소 삭제시
	if (idx == 0) {
		removeFirst(list);
		return;
	}

	Node* curr = list->head;

	// 여기서는 idx 값으로 반복 횟수를 확정할 수 있기 때문에 while이 아닌 for 사용
	for (int i = 0; i < idx - 1; i++) {
		curr = curr->link;
	}
	// curr에는 삭제하기 이전 노드가 들어가있다.
	Node* removeNode = curr->link;
	curr->link = removeNode->link;
	free(removeNode);

}

// 수정
// 첫 번째 요소 수정하기
void updateFirst(List* list, int element) {
	// 요소가 없을 경우
	if (list->head == NULL) {
		printf("데이터가 없습니다!");
		return;
	}
	list->head->data = element;
}

// 인덱스 번호로 요소 수정하기
void update(List* list, int idx, int element) {
	if (idx < 0 || idx > len(list) - 1) {
		printf("ERROR: 인덱스 범위 오류\n");
		return;
	}

	// 0번째 요소 수정시
	if (idx == 0) {
		updateFirst(list, element);
		return;
	}

	Node* curr = list->head;

	// 여기서는 idx 값으로 반복 횟수를 확정할 수 있기 때문에 while이 아닌 for 사용
	for (int i = 0; i < idx; i++) {
		curr = curr->link;
	}
	curr->data = element;
}

// 검색
void select(List* list, int idx, int* res) {
	if (idx >= len(list) || idx < 0) {
		printf("ERROR: 인덱스 범위 오류\n");
		*res = NULL;
		return;
	}

	Node* curr = list->head;

	for (int i = 0; i < idx; i++) {
		curr = curr->link;
	}
	
	*res = curr->data;
}


int main() {
	List list;
	init(&list);
	insertFirst(&list, 10);
	append(&list, 20);
	append(&list, 30);
	append(&list, 40);
	show(&list);
	insert(&list, 0, 5);
	show(&list);
	insert(&list, 3, 555);
	show(&list);
	printf("현재 리스트의 길이: %d\n", len(&list));
	insert(&list, -1, 555);
	show(&list);
	insert(&list, 10, 555);
	show(&list);
	removeFirst(&list);
	printf("\n-----맨 앞 요소 삭제 테스트-----\n");
	show(&list);
	append(&list, 60);
	show(&list);
	printf("\n-----맨 뒤 요소 삭제 테스트-----\n");
	removeLast(&list);
	show(&list);
	append(&list, 70);
	show(&list);
	printf("\n-----인덱스 번호로 요소 삭제 테스트-----\n");
	removeByIdx(&list, 3);
	show(&list);
	printf("\n-----맨 앞 요소 수정 테스트-----\n");
	updateFirst(&list, 777);
	show(&list);
	printf("\n-----인덱스 번호로 요소 수정 테스트-----\n");
	update(&list, 3, 333);
	show(&list);

	int res;
	select(&list, 2, &res);
	printf("검색 결과는 %d입니다.\n", res);

	return 0;
}