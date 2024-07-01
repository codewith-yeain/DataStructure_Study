#include <stdio.h>

int main() {

	int ar[] = { 1, 2, 3 };
	printf("ar: %p\n", ar);

	int num1 = 0;
	int num2 = 100;

	int* ptr = &num1;
	printf("ptr: %p\n", ptr);

	ptr = &num2; // 포인터 변수는 주소를 알고 있으며, 다른 주소값을 대입할 수 있다.
	printf("ptr: %p\n", ptr);

	// 배열은 주소를 알고 있긴 하지만, 다른 주소값을 대입할 수는 없다.
	// ar = &num1;

	ptr = ar;
	printf("ptr: %d\n", *(ptr + 2));

	// 배열 형태의 문자열은 포인터 상수
	// 포인터 형태의 문자열은 상수 포인터




	return 0;

}