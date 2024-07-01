#include <stdio.h>

// 1부터 사용자가 입력한 값까지 곱해주는 함수
int factorial(int num) {
	int res = 1;

	for (int i = 1; i <= num; i++) {
		res *= i;
	}

	return res;
}


int re_fac(int num) { // 스택 구조
	if (num == 1) {
		return 1;
	}

	return num * re_fac(num - 1);
}

int main() {
	
	printf("factorial(5)의 결과: %d\n", factorial(5));
	printf("re_fac(5)의 결과: %d\n", re_fac(5));

	return 0;
}