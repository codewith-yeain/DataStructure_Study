#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct PhysicalCheck {
	int num; // ȸ�� ��ȣ
	int age; // ����
	char name[30]; // �̸�
	double height; // Ű
	double weight; // ������
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
	// ���� ����, �� ��常 �ִ� ��Ȳ���� �߿�ڡڡڡڡڱ׷��� �� �򰥸�!
	// ���� ����, �����Ҵ� �� ��� �ִ� �۾�
	// �����Ҵ�� �ּҸ� ����Ű�� �۾�
	list->head = (Node*)malloc(sizeof(Node));
	list->tail = (Node*)malloc(sizeof(Node));

	// ���� ���� ��� �ּҿ� ������ �ּҸ� �־��ֱ�
	list->head->rlink = list->tail;

	// ���� ���� ó���ִ� ģ���̱⿡, �տ� ��尡 �������� �ʴ´�.
	// �׷��� �ڱ� �ڽ��� ����Ű���� ����
	list->head->llink = list->head;

	// ������ ���� �������� �ִ� ģ���̱⿡, �ڿ� ��尡 �������� �ʴ´�.
	// �׷��� �ڱ� �ڽ��� ����Ű���� ����
	list->tail->llink = list->head;
	list->tail->rlink = list->tail;
}


// �߰�
// �� �տ� �߰��ϱ�
void insertFirst(Dlist* list, Physic element) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = element;

	newNode->llink = list->head;
	newNode->rlink = list->head->rlink; // ������ ���̴� ���� ����
//	newNode->rlink = list->tail; �̷��� ������ ������ ����

	// �Ʒ��� �� �ڵ��� ������ �ٲٸ�
	// �� �տ� �������� ��, �ڿ� �ִ� ����� �ּҸ� �Ҿ���� �� �ִ�.
	// �׻� �ּҸ� �ٲ��ִ� �۾��� �� ��, � ������ �ؾ� ȿ����������
	// �����ؾ��Ѵ�.
	list->head->rlink->llink = newNode;
	list->head->rlink = newNode;
}



// �� �ڿ� �߰��ϱ�
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
		curr = curr->rlink; // �������� data �� �ִ� ģ���� ����
		printf("%-----d���� ����-----\n", curr->data.num);
		printf("�̸�: %s��\n", curr->data.name);
		printf("����: %d��\n", curr->data.age);
		printf("Ű: %.2lf\n", curr->data.height);
		printf("������: %.2lf\n", curr->data.weight);
		printf("---------------------\n\n");
	}
}

// ����Ʈ ���̸� return �ϴ� �Լ�(����� ����->���� ������ �������� �ʴ´�)
// ����Ʈ ����� ������ �˷��ִ� �Լ�
int len(Dlist* list) {
	//if (list->head->rlink = list->tail) {
	//	return 0;
	//}
	// ���� ��Ұ� 0����� length�� ����ִ� 0�� return �� ���̱� ������
	// ���� ó������ �ʿ䰡 ����.

	int length = 0;
	Node* curr = list->head;

	while (curr->rlink != list->tail) {
		curr = curr->rlink;
		length++;
	}

	return length;
}


// �ε��� ��ȣ�� �߰��ϱ�
void insertByIdx(Dlist* list, int idx, Physic element){
	int length = len(list);

	if (idx<0 || idx >length) {
		printf("ERROR: �ε��� ���� ����\n");
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
		// �ݺ��� ������ curr���� ���� �����ϰ��� �ϴ� ��ġ�� �� ��尡 ����ִ�.
	}
	else {
		curr = list->tail;
		for (int i = length; i > idx; i--) {
			curr = curr->llink;
		} // �ݺ��� ������ curr���� ���� �����ϰ��� �ϴ� ��ġ�� ��尡 ����ִ�.

		curr = curr->llink; // ������ ���� �����ϰ��� �ϴ� ��ġ�� �� ��带 ����Ű�� ��.
	}
	
	newNode->rlink = curr->rlink;
	newNode->llink = curr;

	curr->rlink->llink = newNode;
	curr->rlink = newNode;

}

// ����
// ù ��° ��� ����
void removeFirst(Dlist* list) {
	// ����Ʈ�� ����� ���
	if (list->head->rlink == list->tail) {
		printf("ERROR: ����Ʈ�� �������");
		return;
	}
	Node* removeNode = list->head->rlink; // ������ ���
	removeNode->rlink->llink = list->head;
	list->head->rlink = removeNode->rlink;
	free(removeNode);
}

// ������ ��� ����
void removeLast(Dlist* list) {
	// ����Ʈ�� ����� ���
	if (list->head->rlink == list->tail) {
		printf("ERROR: ����Ʈ�� �������");
		return;
	}
	Node* removeNode = list->tail->llink; // ������ ���
	removeNode->llink->rlink = list->tail;
	list->tail->llink = removeNode->llink;

	free(removeNode);
}

// �ε��� ��ȣ�� ����
void removeByIdx(Dlist* list, int idx) {
	int length = len(list);
	if(idx < 0 || idx >= length){
		printf("ERROR: �ε��� ����\n");
		return;
	}

	Node* removeNode; // ������ ������ �ʱ�ȭ���� �ʰ� �ڵ带 �ۼ��ϴ� ���� ��ǻ� ����õ(���� �� ������ ��)
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

// �ε��� ��ȣ�� ����
void updateByIdx(Dlist* list, int idx, Physic element) {
	// �ε��� ���� ��� �ڵ嵵 �ۼ�
	// ������ ã����, ���Ϻ��� ã���� �Ű�X
	// ������ ã��!
	int length = len(list);
	if (idx < 0 || idx > length - 1) {
		printf("ERROR!! : �ε��� ����\n");
		return;
	}
	Node* curr = list->head;
	for (int i = 0; i < idx + 1; i++) {
		curr = curr->rlink;
	}
	curr->data = element;
}


// �˻�
int selectByNum(Dlist* list, int num, Physic* res) {
	Node* curr = list->head;
	while (curr->rlink != list->tail) {
		curr = curr->rlink;
		if (curr->data.num == num) {
			*res = curr->data;
			return 1;
		}
	}
	printf("ERROR: �ش�ȸ����ȣ����\n");
	return 0;
}


// ȸ����ȣ�� ����
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

	// ���� while�� ���� �ִ� if�� �ȿ� ���� �ʰ� while���� ����Ǿ��ٸ�
	// removeNode���� ������ tail�� �� ��尡 ��� �ְ� �ȴ�.
	// �׷��� ������ �ּ� �ٲٴ� �ڵ尡 ����Ǵ� ���� �����ϱ� ���ؼ�
	// �÷��׸� �ϳ� ���� �ڵ带 �������ִ� ���̴�.

	if (check == 0) {
		printf("ERROR: �ش� ȸ�� ��ȣ ����\n");
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

	// ������ ����ü
	Physic p4 = { 4, 25, "Lee", 161.3, 56.1 };


	insertFirst(&list, p1);
	show(&list);
	append(&list, p2);
	insertByIdx(&list, 2, p3);
	show(&list);


	//printf("ù ��° ��� ����---------------------\n");
	//removeFirst(&list);
	//show(&list);
	//printf("�� ��° ��� ����---------------------\n");
	//removeLast(&list);
	//show(&list);

	printf("\n�ε��� ��ȣ�� ��� ���� ------------\n");
	removeByIdx(&list, 2);
	show(&list);

	//printf("\n�ε��� ��ȣ�� ��� ���� ------------\n");
	//updateByIdx(&list, 0, p4);
	//show(&list);

	Physic res;
	if (selectByNum(&list, 1, &res)) {
		printf("<< �˻� ��� >>");
		printf("%-----d���� ����-----\n", res.num);
		printf("�̸�: %s��\n", res.name);
		printf("����: %d��\n", res.age);
		printf("Ű: %.2lf\n", res.height);
		printf("������: %.2lf\n", res.weight);
		printf("---------------------\n\n");
	}
	
	return 0;
}