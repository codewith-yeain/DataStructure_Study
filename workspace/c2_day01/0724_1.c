#include <stdio.h>

int main() {

	int ar[] = { 1, 2, 3 };
	printf("ar: %p\n", ar);

	int num1 = 0;
	int num2 = 100;

	int* ptr = &num1;
	printf("ptr: %p\n", ptr);

	ptr = &num2; // ������ ������ �ּҸ� �˰� ������, �ٸ� �ּҰ��� ������ �� �ִ�.
	printf("ptr: %p\n", ptr);

	// �迭�� �ּҸ� �˰� �ֱ� ������, �ٸ� �ּҰ��� ������ ���� ����.
	// ar = &num1;

	ptr = ar;
	printf("ptr: %d\n", *(ptr + 2));

	// �迭 ������ ���ڿ��� ������ ���
	// ������ ������ ���ڿ��� ��� ������




	return 0;

}