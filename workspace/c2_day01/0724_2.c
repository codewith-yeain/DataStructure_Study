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
	printf("정수 하나를 입력하세요 >>");
	scanf_s("%d", &number);
	int result = howManySeven(number);

	printf("%d과 %d 사이 7의 배수는 %d개입니다.", number, number + 200, result);

	return 0;
}