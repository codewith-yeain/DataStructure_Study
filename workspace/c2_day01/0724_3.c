#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void convertCentiToMeter(int height) {
	
	double result;

	result = height / 100.0;
	printf("���: %.2f m\n", result);
}


int main() {
	int height;
	printf("Ű�� cm ������ �Է��ϼ��� :");

	scanf_s("%d", &height);
	convertCentiToMeter(height);

	return 0;
}
