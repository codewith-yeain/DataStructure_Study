#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // malloc()�� ���ǵǾ� �ִ� �������


struct Student {
	int score;
};



int main() {
	// int�� ���� �Ҵ� �ϰڴ�.
	// void* : � Ÿ���� �ּҷ� �Ѱ����� �������� ���߱� ������ void Ÿ���� �ּҷ� �Ѱ��ش�.
	int* ptr = (int*)malloc(sizeof(int));

	printf("ptr��ġ: %d\n", ptr);
	printf("�����Ҵ�� ��ġ: %d\n", &ptr);

	printf("�����Ҵ�� ���� �ȿ� ����ִ� ��: %d\n", *ptr);
	*ptr = 100;
	printf("�����Ҵ�� ���� �ȿ� ����ִ� ��: %d\n", *ptr);

	free(ptr); // �����Ҵ�� �ּҸ� ������Ų��.

	// ������ ���Ŀ��� �ش� ������ ����� �� ����.

	/**ptr = 300;
	printf("�����Ҵ�� ���� �ȿ� ����ִ� ��: %d\n", *ptr);*/
	
	// calloc(����, ũ��): �������� �Ҵ�����ָ鼭 ���ÿ� �ʱ�ȭ���� �����Ѵ�.
	ptr = (int*)calloc(1, sizeof(int));
	printf("*ptr: %d\n", *ptr);
	free(ptr); 

	struct Student* stPtr = malloc(sizeof(struct Student));
	// �������� �Ҵ���� ������ ��������� �� �����ϱ�
	stPtr->score = 100;
	(*stPtr).score = 100;
	free(stPtr);

	// int Ÿ���� ��Ұ� 5�� ����ִ� �迭
	// 20����Ʈ

	int* ar = (int*)malloc(sizeof(int) * 5);
	printf("&ar: %d\n", &ar);
	printf("�������� �Ҵ���� �ּ�: %d\n", ar);
	
	ar[0] = 10; // *ar = 10;

	printf("ar[0]�� ��: %d\n", ar[0]);

	int* ar2 = (int*)calloc(5, sizeof(int));

	for (int i = 0; i < 5; i++) {
		ar2[i] = i * 10;
	}

	for (int i = 0; i < 5; i++) {
		printf("ar2[%d]: %d\n", i, ar2[i]);
	}

	// sizeof()�� ����ؼ� �����Ҵ�� �޸� ũ�⸦ �� �� �ִ� ���� �ƴϴ�.
	printf("ar2�� �ּ�: %d\n", &ar2);
	printf("ar2�� ������: %d\n", sizeof(ar2));

	free(ar2);
	return 0;
}

