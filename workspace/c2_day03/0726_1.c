#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // malloc()이 정의되어 있는 헤더파일


struct Student {
	int score;
};



int main() {
	// int를 동적 할당 하겠다.
	// void* : 어떤 타입의 주소로 넘겨줄지 결정하지 못했기 때문에 void 타입의 주소로 넘겨준다.
	int* ptr = (int*)malloc(sizeof(int));

	printf("ptr위치: %d\n", ptr);
	printf("동적할당된 위치: %d\n", &ptr);

	printf("동적할당된 공간 안에 들어있는 값: %d\n", *ptr);
	*ptr = 100;
	printf("동적할당된 공간 안에 들어있는 값: %d\n", *ptr);

	free(ptr); // 동적할당된 주소를 해제시킨다.

	// 해제된 이후에는 해당 공간을 사용할 수 없다.

	/**ptr = 300;
	printf("동적할당된 공간 안에 들어있는 값: %d\n", *ptr);*/
	
	// calloc(갯수, 크기): 동적으로 할당시켜주면서 동시에 초기화까지 진행한다.
	ptr = (int*)calloc(1, sizeof(int));
	printf("*ptr: %d\n", *ptr);
	free(ptr); 

	struct Student* stPtr = malloc(sizeof(struct Student));
	// 동적으로 할당받은 공간의 멤버변수에 값 대입하기
	stPtr->score = 100;
	(*stPtr).score = 100;
	free(stPtr);

	// int 타입의 요소가 5개 들어있는 배열
	// 20바이트

	int* ar = (int*)malloc(sizeof(int) * 5);
	printf("&ar: %d\n", &ar);
	printf("동적으로 할당받은 주소: %d\n", ar);
	
	ar[0] = 10; // *ar = 10;

	printf("ar[0]의 값: %d\n", ar[0]);

	int* ar2 = (int*)calloc(5, sizeof(int));

	for (int i = 0; i < 5; i++) {
		ar2[i] = i * 10;
	}

	for (int i = 0; i < 5; i++) {
		printf("ar2[%d]: %d\n", i, ar2[i]);
	}

	// sizeof()를 사용해서 동적할당된 메모리 크기를 알 수 있는 것은 아니다.
	printf("ar2의 주소: %d\n", &ar2);
	printf("ar2의 사이즈: %d\n", sizeof(ar2));

	free(ar2);
	return 0;
}

