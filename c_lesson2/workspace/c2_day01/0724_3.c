#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void convertCentiToMeter(int height) {
	
	double result;

	result = height / 100.0;
	printf("결과: %.2f m\n", result);
}


int main() {
	int height;
	printf("키를 cm 단위로 입력하세요 :");

	scanf_s("%d", &height);
	convertCentiToMeter(height);

	return 0;
}
