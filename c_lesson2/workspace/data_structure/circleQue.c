#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 5

typedef struct CircleQueue {
	int ar[MAX];
	int length; // 큐 요소의 갯수를 저장할 변수
	int front; // dequeue() 시 큐에서 삭제할 인덱스
	int rear; // enqueue() 시 큐에 추가할 인덱스
}Que;

// 초기화 함수
void init(Que* q) {
	q->length = 0;
	q->front = 0;
	q->rear = 0;
}


int isFull(Que* q) {
	return q->length == MAX;
}

int isEmpty(Que* q) {
	return q->length == 0;
}


// enqueue(): 데이터 삽입. rear 부분에 삽입한다.
void enqueue(Que* q, int element) {
	if (isFull(q)) {
		printf("ERROR: 큐가 가득 차 있음\n");
		return;
	}

	q->ar[q->rear] = element;
	q->length++;

	// rear는 맨 마지막이라면 다시 맨 앞으로 이동해야 하기 때문에
	// 나머지 연산자를 활용하여 0번 인덱스를 가리키게 만들 수 있다.
	q->rear = (q->rear + 1) % MAX;

}

// dequeue(): 해당 큐에서 요소를 삭제한다.
// front에 존재하는 요소 삭제, 삭제된 정보도 알려주자.
void dequeue(Que* q, int* res) {
	if (isEmpty(q)) {
		printf("ERROR: 큐가 비어 있음\n");
		return;
	}

	*res = q->ar[q->front]; // res에 삭제할 예정인 데이터를 담아준다.
	q->length--; // 길이를 1 줄여준다.

	q->front = (q->front + 1) % MAX; // front를 옮겨준다.
}

// peek(): front에 담겨있는 데이터를 매개변수로 넘어온 주소에 저장
void peek(Que* q, int* res) {
	if (isEmpty(q)) {
		printf("ERROR: 큐가 비어 있음\n");
		return;
	}

	*res = q->ar[q->front];
}

// clear()
void clear(Que* q) {
	q->length = 0;
	q->front = q->rear; // q->rear는 무조건 비어있음
}

// show(): 큐 안에 들어있는 요소를 확인
void show(Que* q) {
	if (isEmpty(q)) {
		printf("현재 Que는 비어있습니다.\n");
		return;
	}



	int idx = q->front;

	printf("\n--------front: %d, rear: %d--------\n", q->front, q->rear);

	for (int i = 0; i < q->length; i++) {
		printf("%d |", q->ar[idx]);
		idx = (idx + 1) % MAX;

	}

	printf("\n---------------------\n");
}

int main() {
	Que q;
	init(&q);

	while (1) {
		int choice;
		int res;
		printf("(1)enqueue (2)dequeue (3)peek (4)claer (5)show (6)exit\n");
		scanf_s("%d", &choice);

		if (choice == 1) { // enqueue
			printf("input num >>");
			scanf("%d", &choice);
			enqueue(&q, choice);
		}
		else if (choice == 2) { // dequeue
			dequeue(&q, &res);
			printf("dequeue된 값: %d\n", res);
		}
		else if (choice == 3) {
			peek(&q, &res);
			printf("peek한 값: %d\n", res);
		}
		else if (choice == 4) clear(&q);
		else if (choice == 5) show(&q);
		else if (choice == 6) break;
		else {
			printf("다시 입력해주세요\n");
		}
	}

	printf("Que 테스트를 종료합니다.\n");

	return 0;
}