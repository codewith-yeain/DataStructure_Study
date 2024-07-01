#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data; // �������� ����Ʈ�� ��Ұ� ����� ����
	struct Node* link; // ������ ���� �ٱ� ���̶� �տ� struct�� �� �ٿ������(���� typedef Node�� ���ǵ��� ���� ����)
}Node;

typedef struct LinkedList {
	Node* head; // ���� ù ��° ���� ����� �ּҸ� ��� ������ �� ���̴�.
}List;


// �ʱ�ȭ �Լ�
void init(List* list) {
	list->head = NULL;
};

// ��� Ȯ�ο� show �Լ�
void show(List* list) {
	// ��ȸ�� ������
	Node* curr = list->head; // curr���� ù ��° ��带 ����ش�.
	while (curr != NULL)
	{
		printf("[%d]->", curr->data);
		curr = curr->link;
	}
	printf("\n");
}

// �߰�
// �� �տ� �߰��ϱ�
// List�� �����͸� ó�� �߰��� �� ����� �Լ�

void insertFirst(List* list, int element) {
	// ���Ӱ� �߰��� ���� �� �Լ� ȣ���� �������� �޸𸮿� �����־�� �Ѵ�.
	// ���� ���޸𸮿� �����Ҵ��� ���ش�.
	Node* newNode = (Node*)malloc(sizeof(Node));
	// newNode ���� ���Ӱ� ������� ��尡 �Ҵ�� �ּҰ� ����ִ�.
	newNode->data = element;
	newNode->link = list->head;
	list->head = newNode;
	//printf("%d����� �ּ� : %d\n", element, newNode);
}

// ������ �߰�
void append(List* list, int element) {
	// ����Ʈ�� ��Ұ� �ϳ��� ���ٸ�
	if (list->head == NULL) {
		insertFirst(list, element); // �� ó���� ��Ҹ� �߰��Ѵ�.
		return; // �Լ� ������ �ǹ̷� ���
	}

	Node* curr = list->head;
	while (curr->link != NULL) {
		curr = curr->link;
	}
	// �ݺ����� �� ������ curr���� ������ ��尡 ����ִ�.
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = element;
	newNode->link = NULL;
	curr->link = newNode;
}

// ����Ʈ ����� ������ �˷��ִ� �Լ�
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
	// �ݺ����� �� ������ �ȴٸ� length���� ����Ʈ ����� ������ ���� �ȴ�.
	return length;
}


// �����͸� �߰��� �߰��ϱ�
// �ε��� ��ȣ�� Ȱ���Ͽ� �߰��ϱ�
void insert(List* list, int idx, int element) {

	// �ε��� ��ȣ�� �����̰ų� ���̺��� Ŭ ���
	if (idx < 0 || idx > len(list)) {
		printf("ERROR: �ε��� ���� ����\n");
		return;
	}

	// �����ϰ��� �ϴ� idx�� 0���� ���
	if (idx == 0) {
		insertFirst(list, element);
		return;
	}

	Node* curr = list->head;

	// ���⼭�� idx ������ �ݺ� Ƚ���� Ȯ���� �� �ֱ� ������ while�� �ƴ� for ���
	for (int i = 0; i < idx - 1; i++) {
		curr = curr->link;
	}
	// �ݺ����� �� ���� ������ curr���� ���� ������ ���� ��尡 ����ִ�.
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = element;

	// �Ʒ��� �ڵ尡 ������ �ٲ�� ���� �ȵ�
	newNode->link = curr->link;
	curr->link = newNode;
}

// ����
// �� ���� ��� ����
void removeFirst(List* list) {
	// ����Ʈ�� ����ִٸ�
	if (list->head == NULL) {
		printf("�����Ͱ� �ƹ��͵� �����ϴ�.");
		return;
	}

	
	// �츮�� ������ ���� head�� ����ִ� �ּ��̴�.
	// ������, �� �ּҸ� �ٷ� �����ع����ٸ�, ��ũ�帮��Ʈ�� ���� �ּҸ� �Ҿ������ ���̱⿡
	// �����ϱ� ���� head�� �� ��° ����� �ּҸ� ������ �Ѵ�.
	// �׷��� �ȴٸ�, ���� �����Ҵ� ���� �ϰ� ���� �ּҸ� �Ҿ������ ������,
	// �� ���� �����͸� �ϳ� ����, ���� �����ϰ� ���� ����� �ּҸ� ��� ���´�.
	// [���� ����] ù ��° ��尡 �� ������ ����� �ּҸ� ã�� ���� ������ ��带 ��´�.

	Node* removeNode = list->head; // ������ ���
	list->head = removeNode->link; // head�� ù ��° ��尡 �� ������ ����� �ּҸ� ��´�.
	free(removeNode); // ù ��° ��带 �����Ѵ�.
}

// ������ ��� �����ϱ�
void removeLast(List* list) {
	// ����Ʈ�� ����ִٸ�
	if (list->head == NULL) {
		printf("�����Ͱ� �ƹ��͵� �����ϴ�.");
		return;
	}

	if (len(list) == 1) {
		removeFirst(list);
		return;
	}
	// ����Ʈ ��Ұ� �� �� ������� ���
	// curr->link�� NULL�̱� ������
	// curr->link->link�� ��ǻ� NULL->link�� �ǹ��ϰ� �ȴ�.
	// ���� ������ �߻��Ѵ�.
	Node* curr = list->head;

	while (curr->link->link != NULL) {
		curr = curr->link;
	}
	// �ݺ��� ������ curr���� ������ ���� ��尡 ����ִ�.
	free(curr->link);
	curr->link = NULL;
}

// �ε��� ��ȣ�� �����ϱ�
void removeByIdx(List* list, int idx) {
	if (idx < 0 || idx > len(list)-1) {
		printf("ERROR: �ε��� ���� ����\n");
		return;
	}

	// 0��° ��� ������
	if (idx == 0) {
		removeFirst(list);
		return;
	}

	Node* curr = list->head;

	// ���⼭�� idx ������ �ݺ� Ƚ���� Ȯ���� �� �ֱ� ������ while�� �ƴ� for ���
	for (int i = 0; i < idx - 1; i++) {
		curr = curr->link;
	}
	// curr���� �����ϱ� ���� ��尡 ���ִ�.
	Node* removeNode = curr->link;
	curr->link = removeNode->link;
	free(removeNode);

}

// ����
// ù ��° ��� �����ϱ�
void updateFirst(List* list, int element) {
	// ��Ұ� ���� ���
	if (list->head == NULL) {
		printf("�����Ͱ� �����ϴ�!");
		return;
	}
	list->head->data = element;
}

// �ε��� ��ȣ�� ��� �����ϱ�
void update(List* list, int idx, int element) {
	if (idx < 0 || idx > len(list) - 1) {
		printf("ERROR: �ε��� ���� ����\n");
		return;
	}

	// 0��° ��� ������
	if (idx == 0) {
		updateFirst(list, element);
		return;
	}

	Node* curr = list->head;

	// ���⼭�� idx ������ �ݺ� Ƚ���� Ȯ���� �� �ֱ� ������ while�� �ƴ� for ���
	for (int i = 0; i < idx; i++) {
		curr = curr->link;
	}
	curr->data = element;
}

// �˻�
void select(List* list, int idx, int* res) {
	if (idx >= len(list) || idx < 0) {
		printf("ERROR: �ε��� ���� ����\n");
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
	printf("���� ����Ʈ�� ����: %d\n", len(&list));
	insert(&list, -1, 555);
	show(&list);
	insert(&list, 10, 555);
	show(&list);
	removeFirst(&list);
	printf("\n-----�� �� ��� ���� �׽�Ʈ-----\n");
	show(&list);
	append(&list, 60);
	show(&list);
	printf("\n-----�� �� ��� ���� �׽�Ʈ-----\n");
	removeLast(&list);
	show(&list);
	append(&list, 70);
	show(&list);
	printf("\n-----�ε��� ��ȣ�� ��� ���� �׽�Ʈ-----\n");
	removeByIdx(&list, 3);
	show(&list);
	printf("\n-----�� �� ��� ���� �׽�Ʈ-----\n");
	updateFirst(&list, 777);
	show(&list);
	printf("\n-----�ε��� ��ȣ�� ��� ���� �׽�Ʈ-----\n");
	update(&list, 3, 333);
	show(&list);

	int res;
	select(&list, 2, &res);
	printf("�˻� ����� %d�Դϴ�.\n", res);

	return 0;
}