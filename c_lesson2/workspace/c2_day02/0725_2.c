# define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>
# include <string.h>

typedef struct Student {
	char name[30];
	int score;
} Student;

int main() {
	/*Student S1 = {"김철수", 80};
	Student S2 = { "홍길동", 50 };
	Student S3 = { "김수미", 60 };*/

	// 구조체 배열
	Student ar[] = {
		{ "김철수", 80 },
		{ "홍길동", 50 },
		{ "김수미", 60 }
	};
	// [실습]
	// "홍길동"만 출력되게 코드를 한 번 만들어보세요!
	printf("ar[1].name: %s\n", ar[1].name);

	// 구조체 포인터
	// 포인터는 포인터인데, 구조체 변수의 주소값을 담아주는 포인터

	Student ryu = {"류호근", 100};
	Student* sptr = &ryu; // 구조체 포인터
	printf("ryu의 주소값: %d\n", &ryu);
	printf("ryu의 주소값: %d\n", sptr);

	// 구조체 변수 자체는 주소가 아니다! &를 붙여야 주소가 나오는 것이다!
	// *sptr: ryu
	// (*sptr).name: ryu.name

	(*sptr).score = 50;

	// 구조체 포인터를 통해 멤버변수 접근하기
	printf("(*sptr).name: %s\n", (*sptr).name);
	printf("(*sptr).score: %d\n", (*sptr).score);

	// ->
	printf("sptr -> name: %s\n", sptr -> name);
	printf("sptr -> score: %d\n", sptr -> score);


	
	return 0;
}