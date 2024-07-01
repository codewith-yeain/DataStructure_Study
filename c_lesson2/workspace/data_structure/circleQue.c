#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 5

typedef struct CircleQueue {
	int ar[MAX];
	int length; // ť ����� ������ ������ ����
	int front; // dequeue() �� ť���� ������ �ε���
	int rear; // enqueue() �� ť�� �߰��� �ε���
}Que;

// �ʱ�ȭ �Լ�
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


// enqueue(): ������ ����. rear �κп� �����Ѵ�.
void enqueue(Que* q, int element) {
	if (isFull(q)) {
		printf("ERROR: ť�� ���� �� ����\n");
		return;
	}

	q->ar[q->rear] = element;
	q->length++;

	// rear�� �� �������̶�� �ٽ� �� ������ �̵��ؾ� �ϱ� ������
	// ������ �����ڸ� Ȱ���Ͽ� 0�� �ε����� ����Ű�� ���� �� �ִ�.
	q->rear = (q->rear + 1) % MAX;

}

// dequeue(): �ش� ť���� ��Ҹ� �����Ѵ�.
// front�� �����ϴ� ��� ����, ������ ������ �˷�����.
void dequeue(Que* q, int* res) {
	if (isEmpty(q)) {
		printf("ERROR: ť�� ��� ����\n");
		return;
	}

	*res = q->ar[q->front]; // res�� ������ ������ �����͸� ����ش�.
	q->length--; // ���̸� 1 �ٿ��ش�.

	q->front = (q->front + 1) % MAX; // front�� �Ű��ش�.
}

// peek(): front�� ����ִ� �����͸� �Ű������� �Ѿ�� �ּҿ� ����
void peek(Que* q, int* res) {
	if (isEmpty(q)) {
		printf("ERROR: ť�� ��� ����\n");
		return;
	}

	*res = q->ar[q->front];
}

// clear()
void clear(Que* q) {
	q->length = 0;
	q->front = q->rear; // q->rear�� ������ �������
}

// show(): ť �ȿ� ����ִ� ��Ҹ� Ȯ��
void show(Que* q) {
	if (isEmpty(q)) {
		printf("���� Que�� ����ֽ��ϴ�.\n");
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
			printf("dequeue�� ��: %d\n", res);
		}
		else if (choice == 3) {
			peek(&q, &res);
			printf("peek�� ��: %d\n", res);
		}
		else if (choice == 4) clear(&q);
		else if (choice == 5) show(&q);
		else if (choice == 6) break;
		else {
			printf("�ٽ� �Է����ּ���\n");
		}
	}

	printf("Que �׽�Ʈ�� �����մϴ�.\n");

	return 0;
}