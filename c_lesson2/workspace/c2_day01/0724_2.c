# define _CRT_SECURE_NO_WAR
# include <stdio.h>

int howManySeven(int number) {
	int count = 0;
	for (int i = number; i <= number + 200; i++) {
		if (i % 7 == 0) {
			count++;
		}
	}

	return count;
}

int main() {
	int number;
	printf("���� �ϳ��� �Է��ϼ��� >>");
	scanf_s("%d", &number);
	int result = howManySeven(number);

	printf("%d�� %d ���� 7�� ����� %d���Դϴ�.", number, number + 200, result);

	return 0;
}