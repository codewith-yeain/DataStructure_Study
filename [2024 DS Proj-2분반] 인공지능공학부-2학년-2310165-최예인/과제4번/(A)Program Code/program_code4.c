// 인공지능공학부, 2310165, 최예인, program_code4.c(미로 탈출 프로그램), 2024년 6월 1일
#include <stdio.h>
#include <stdlib.h>
#include "stackForMaze.h"

void findPath(Stack* s, int x, int y){
    if (x < 0 || y < 0 || x > MAZE_SIZE || y > MAZE_SIZE) return;

    // 길(0)이고 이미 갔던 길(.)이 아닐 때의 경로만 스택에 추가
    if (maze[x][y] !=  1 && maze[x][y] != 4)
    {
        Mouse mouse;
        mouse.x = x;
        mouse.y = y;

        push(s, mouse);
    }
}

int main(){
    Stack s;
    Mouse m;
    int x, y;

    init(&s);

    // 시작점 탐색
    for (int i = 0; i < MAZE_SIZE; i++)
    {
        for (int j = 0; j < MAZE_SIZE; j++)
        {
            if (maze[i][j] == 2)
            {
                m.x = i;
                m.y = j;
            }
        }
    }

    printf("시작 (%d,%d)\n", m.x, m.y);

    while (maze[m.x][m.y] != 3)
    {
        printf("현재 위치: (%d,%d)\n", m.x, m.y);
        x = m.x;
        y = m.y;

        maze[x][y] = 4; // 방문한 곳을 표시

        // 이동 가능한 곳을 탐색
        findPath(&s, x + 1, y);
        findPath(&s, x - 1, y);
        findPath(&s, x, y + 1);
        findPath(&s, x, y - 1);

        printf("\n[ 경로 스택 ]\n");
        show(&s);

        if (is_empty(&s)) {
            printf("이동경로를 찾을 수 없습니다. 실패 \n");
            return 0;
        }
        else {
            m = pop(&s); // 현재 좌표를 변경
            printf("\n이동 위치: (%d,%d)", m.x, m.y);
        }

        printf("\n\n--------------------------------------\n\n");
    }
    printf("도착!\n 탐색 성공\n");

    return 0;
}
