#include <stdio.h>

// 1���� ����ڰ� �Է��� ������ �����ִ� �Լ�
int factorial(int num) {
	int res = 1;

	for (int i = 1; i <= num; i++) {
		res *= i;
	}

	return res;
}


int re_fac(int num) { // ���� ����
	if (num == 1) {
		return 1;
	}

	return num * re_fac(num - 1);
}

int main() {
	
	printf("factorial(5)�� ���: %d\n", factorial(5));
	printf("re_fac(5)�� ���: %d\n", re_fac(5));

	return 0;
}