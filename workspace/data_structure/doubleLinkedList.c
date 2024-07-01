#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct PhysicalCheck {
	int num; // 회원 번호
	int age; // 나이
	char name[30]; // 이름
	double height; // 키
	double weight; // 몸무게
}Physic;

typedef struct Node {
	struct Node* llink; // prev;
	struct Node* rlink; // next;
	Physic data;
} Node;

typedef struct DoubleLinkedList {
	struct Node* head;
	struct Node* tail;
}Dlist;

void init(Dlist* list) {
	// 헤드와 테일, 두 노드만 있는 상황임이 중요★★★★★그래야 안 헷갈림!
	// 헤드와 테일, 동적할당 후 담아 주는 작업
	// 동적할당된 주소를 기억시키는 작업
	list->head = (Node*)malloc(sizeof(Node));
	list->tail = (Node*)malloc(sizeof(Node));

	// 헤드와 다음 노드 주소에 테일의 주소를 넣어주기
	list->head->rlink = list->tail;

	// 헤드는 제일 처음있는 친구이기에, 앞에 노드가 존재하지 않는다.
	// 그래서 자기 자신을 가리키도록 구현
	list->head->llink = list->head;

	// 테일은 제일 마지막에 있는 친구이기에, 뒤에 노드가 존재하지 않는다.
	// 그래서 자기 자신을 가리키도록 구현
	list->tail->llink = list->head;
	list->tail->rlink = list->tail;
}


// 추가
// 맨 앞에 추가하기
void insertFirst(Dlist* list, Physic element) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = element;

	newNode->llink = list->head;
	newNode->rlink = list->head->rlink; // 순서가 꼬이는 것을 방지
//	newNode->rlink = list->tail; 이렇게 적으면 문제가 생김

	// 아래의 두 코드의 순서를 바꾸면
	// 맨 앞에 삽입했을 때, 뒤에 있는 노드의 주소를 잃어버릴 수 있다.
	// 항상 주소를 바꿔주는 작업을 할 때, 어떤 순서로 해야 효과적인지를
	// 생각해야한다.
	list->head->rlink->llink = newNode;
	list->head->rlink = newNode;
}



// 맨 뒤에 추가하기
void append(Dlist* list, Physic element) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = element;

	newNode->rlink = list->tail;
	newNode->llink = list->tail->llink;

	list->tail->llink->rlink = newNode;
	list->tail->llink = newNode;

}

void show(Dlist* list) {
	Node* curr = list->head;
	
	while (curr->rlink != list->tail) {
		curr = curr->rlink; // 이제부터 data 가 있는 친구가 들어옴
		printf("%-----d번의 정보-----\n", curr->data.num);
		printf("이름: %s님\n", curr->data.name);
		printf("나이: %d살\n", curr->data.age);
		printf("키: %.2lf\n", curr->data.height);
		printf("몸무게: %.2lf\n", curr->data.weight);
		printf("---------------------\n\n");
	}
}

// 리스트 길이를 return 하는 함수(요소의 갯수->헤드와 테일은 포함하지 않는다)
// 리스트 요소의 갯수를 알려주는 함수
int len(Dlist* list) {
	//if (list->head->rlink = list->tail) {
	//	return 0;
	//}
	// 만약 요소가 0개라면 length에 들어있는 0이 return 될 것이기 때문에
	// 따로 처리해줄 필요가 없다.

	int length = 0;
	Node* curr = list->head;

	while (curr->rlink != list->tail) {
		curr = curr->rlink;
		length++;
	}

	return length;
}


// 인덱스 번호로 추가하기
void insertByIdx(Dlist* list, int idx, Physic element){
	int length = len(list);

	if (idx<0 || idx >length) {
		printf("ERROR: 인덱스 범위 오류\n");
		return;
	}

	//if (idx == 0) {
	//	insertFirst(list, element);
	//	return;
	//}

	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = element;

	Node* curr;
	if (idx < length / 2) {
		curr = list->head;
		for (int i = 0; i<idx; i++)
		{
			curr = curr->rlink;
		}
		// 반복이 끝나면 curr에는 내가 삽입하고자 하는 위치의 앞 노드가 들어있다.
	}
	else {
		curr = list->tail;
		for (int i = length; i > idx; i--) {
			curr = curr->llink;
		} // 반복이 끝나면 curr에는 내가 삽입하고자 하는 위치의 노드가 들어있다.

		curr = curr->llink; // 이제는 내가 삽입하고자 하는 위치의 앞 노드를 가르키게 됨.
	}
	
	newNode->rlink = curr->rlink;
	newNode->llink = curr;

	curr->rlink->llink = newNode;
	curr->rlink = newNode;

}

// 삭제
// 첫 번째 요소 삭제
void removeFirst(Dlist* list) {
	// 리스트가 비었을 경우
	if (list->head->rlink == list->tail) {
		printf("ERROR: 리스트가 비어있음");
		return;
	}
	Node* removeNode = list->head->rlink; // 삭제할 노드
	removeNode->rlink->llink = list->head;
	list->head->rlink = removeNode->rlink;
	free(removeNode);
}

// 마지막 요소 삭제
void removeLast(Dlist* list) {
	// 리스트가 비었을 경우
	if (list->head->rlink == list->tail) {
		printf("ERROR: 리스트가 비어있음");
		return;
	}
	Node* removeNode = list->tail->llink; // 삭제할 노드
	removeNode->llink->rlink = list->tail;
	list->tail->llink = removeNode->llink;

	free(removeNode);
}

// 인덱스 번호로 삭제
void removeByIdx(Dlist* list, int idx) {
	int length = len(list);
	if(idx < 0 || idx >= length){
		printf("ERROR: 인덱스 오류\n");
		return;
	}

	Node* removeNode; // 포인터 변수는 초기화하지 않고 코드를 작성하는 것이 사실상 비추천(빌드 시 오류가 남)
	if (idx < length/2) {
		removeNode = list->head;
		for (int i = 0; i <= idx; i++) {
			removeNode = removeNode->rlink;
		}
	}
	else {
		removeNode = list->tail;
		for (int i = length; i > idx; i--) {
			removeNode = removeNode->llink;
		}
	}

	removeNode->llink->rlink = removeNode->rlink;
	removeNode->rlink->llink = removeNode->llink;
	
	free(removeNode);
}

// 인덱스 번호로 수정
void updateByIdx(Dlist* list, int idx, Physic element) {
	// 인덱스 관련 방어 코드도 작성
	// 헤드부터 찾을지, 테일부터 찾을지 신경X
	// 헤드부터 찾기!
	int length = len(list);
	if (idx < 0 || idx > length - 1) {
		printf("ERROR!! : 인덱스 오류\n");
		return;
	}
	Node* curr = list->head;
	for (int i = 0; i < idx + 1; i++) {
		curr = curr->rlink;
	}
	curr->data = element;
}


// 검색
int selectByNum(Dlist* list, int num, Physic* res) {
	Node* curr = list->head;
	while (curr->rlink != list->tail) {
		curr = curr->rlink;
		if (curr->data.num == num) {
			*res = curr->data;
			return 1;
		}
	}
	printf("ERROR: 해당회원번호없음\n");
	return 0;
}


// 회원번호로 삭제
void removeByNum(Dlist* list, int num) {
	Node* removeNode = list->head;
	int check = 0;

	while (removeNode->rlink != list->tail) {
		removeNode = removeNode->rlink;
		if (removeNode->data.num == num) {
			check = 1;
			break;
		}
	}

	// 만약 while문 내에 있는 if문 안에 들어가지 않고 while문이 종료되었다면
	// removeNode에는 무조건 tail의 앞 노드가 담겨 있게 된다.
	// 그렇기 때문에 주소 바꾸는 코드가 실행되는 것을 제어하기 위해서
	// 플래그를 하나 만들어서 코드를 제어해주는 것이다.

	if (check == 0) {
		printf("ERROR: 해당 회원 번호 없음\n");
		return;
	}

	removeNode->llink->rlink = removeNode->rlink;
	removeNode->rlink->llink = removeNode->llink;

	free(removeNode);
}

int main() {

	Dlist list;
	init(&list);

	Physic p1 = { 1, 22, "Ryu", 176.0, 80.2 };
	Physic p2 = { 2, 20, "Kim", 153.0, 45.3 };
	Physic p3 = { 3, 30, "Park", 180.5, 77.7 };

	// 수정용 구조체
	Physic p4 = { 4, 25, "Lee", 161.3, 56.1 };


	insertFirst(&list, p1);
	show(&list);
	append(&list, p2);
	insertByIdx(&list, 2, p3);
	show(&list);


	//printf("첫 번째 요소 삭제---------------------\n");
	//removeFirst(&list);
	//show(&list);
	//printf("두 번째 요소 삭제---------------------\n");
	//removeLast(&list);
	//show(&list);

	printf("\n인덱스 번호로 요소 삭제 ------------\n");
	removeByIdx(&list, 2);
	show(&list);

	//printf("\n인덱스 번호로 요소 수정 ------------\n");
	//updateByIdx(&list, 0, p4);
	//show(&list);

	Physic res;
	if (selectByNum(&list, 1, &res)) {
		printf("<< 검색 결과 >>");
		printf("%-----d번의 정보-----\n", res.num);
		printf("이름: %s님\n", res.name);
		printf("나이: %d살\n", res.age);
		printf("키: %.2lf\n", res.height);
		printf("몸무게: %.2lf\n", res.weight);
		printf("---------------------\n\n");
	}
	
	return 0;
}