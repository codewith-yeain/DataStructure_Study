// 인공지능공학부, 2310165, 최예인, stackForMaze.h, 2024년 6월 1일
#pragma once
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
#define MAZE_SIZE 10

typedef struct Mouse {
    int x;
    int y;
}Mouse;

typedef struct Stack {
    Mouse data[MAX_SIZE];
    int top;
}Stack;

// 길이 0, 벽이 1, 입구(시작점)가 2, 출구(끝점)가 3, 방문한 곳은 4
int maze[MAZE_SIZE][MAZE_SIZE] = {
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    { 2, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    { 1, 0, 0, 0, 1, 0, 0, 1, 0, 1},
    { 1, 0, 1, 1, 1, 0, 0, 1, 0, 1},
    { 1, 0, 0, 0, 1, 0, 0, 1, 0, 1},
    { 1, 0, 1, 0, 1, 0, 0, 1, 0, 1},
    { 1, 0, 1, 0, 1, 0, 0, 1, 0, 1},
    { 1, 0, 1, 0, 1, 0, 0, 1, 0, 1},
    { 1, 0, 1, 0, 0, 0, 0, 1, 0, 3},
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1} };

void init(Stack* p) {
    p->top = -1;
}

int is_full(Stack* p) {
    return (p->top == MAX_SIZE - 1);
}

int is_empty(Stack* p) {
    return (p->top == -1);
}

void push(Stack* p, Mouse data) {
    if (is_full(p))
    {
        printf("스택이 꽉찼습니다.\n"); return;
    }
    else
    {
        p->top++;
        p->data[p->top].x = data.x;
        p->data[p->top].y = data.y;
    }
}

Mouse pop(Stack* p) {
    if (is_empty(p))
    {
        printf("스택이 비어있습니다.\n");
        exit(1);
    }

    return p->data[(p->top)--];
}


void show(const Stack* stack) {
    if (stack->top == -1) {
        printf("스택이 비어있습니다.\n");
        return;
    }

    for (int i = 0; i <= stack->top; ++i) {
        printf("path %d: (x: %d, y: %d)\n", i, stack->data[i].x, stack->data[i].y);
    }
}
