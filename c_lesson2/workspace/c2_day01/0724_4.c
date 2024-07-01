#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void printTime(int second) {
	//int hours, minutes, seconds;

	//hours = second / 3600;
	//minutes = (second % 15) / 60;
	//seconds = second % 60;

	//printf("결과: %d시간/%d분/%d초\n", hours, minutes, seconds);

	int time[3];

	time[0] = second / 3600;
	time[1] = (second % 15) / 60;
	time[2] = second % 60;

	printf("결과: %d시간/%d분/%d초\n", time[0], time[1], time[2]);

}


int main() {
	int second;
	printf("몇 초: ");
	scanf_s("%d", &second);

	printTime(second);

	return 0;
}