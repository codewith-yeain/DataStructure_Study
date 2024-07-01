#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data; // 실질적인 데이터가 저장될 멤버 변수
	struct Node* left; // 왼쪽 자식을 저장할 포인터 변수
	struct Node* right; // 오른쪽 자식을 저장할 포인터 변수
}BinNode;

// show() - 전위, 중위, 후위
// 전위 순회: 본인 방문, 왼쪽 자식, 오른쪽 자식
void proShow(BinNode* node);

// 중위 순회: 왼쪽 자식, 본인 방문, 오른쪽 자식
// 이진탐색트리에서 중위 순회를 사용하면 정렬된 순서대로 탐색할 수 있다.
void inShow(BinNode* node);

// 후위 순회: 왼쪽 자식, 오른쪽 자식, 본인 방문
void postShow(BinNode* node);

// 추가
BinNode* add(BinNode* root, int element);

// 삭제
void removeElement(BinNode* node, int element);

// 검색, 반복문
void search(BinNode* root, int element);

// 검색, 재귀함수
void select_r(BinNode* node, int element);

int main() {
	BinNode* root;
	root = NULL;
	root = add(root, 10); // 최초에 삽입된 데이터가 root 노드가 된다.

	add(root, 5);
	add(root, 7);
	add(root, 15);
	add(root, 13);
	printf("전위 순회: ");
	proShow(root);
	printf("\n");
	printf("중위 순회: ");
	inShow(root);
	printf("\n");
	printf("후위 순회: ");
	postShow(root);
	printf("\n");

	removeElement(root, 5);
	inShow(root);
	printf("\n");
    search(root, 10);
    select_r(root, 100);

	return 0;
}

// 전위 순회: 본인 방문, 왼쪽 자식, 오른쪽 자식
void proShow(BinNode* node) {
	if (node != NULL) {
		printf("[%d] ", node->data);
		proShow(node->left);
		proShow(node->right);
	}
}

// 중위 순회: 왼쪽 자식, 본인 방문, 오른쪽 자식
void inShow(BinNode* node) {
	if (node != NULL) {
		inShow(node->left);
		printf("[%d] ", node->data);
		inShow(node->right);
	}
}

// 후위 순회: 왼쪽 자식, 오른쪽 자식, 본인 방문
void postShow(BinNode* node) {
	if (node != NULL) {
		postShow(node->left);
		postShow(node->right);
		printf("[%d] ", node->data);
	}
}


// 추가
BinNode* add(BinNode* root, int element) {
	if (root == NULL) { // 비어있는 트리라면
		// 추가하고자 하는 노드가 root 노드가 될 것이다.
		root = (BinNode*)malloc(sizeof(BinNode));
		root->data = element;
		root->left = NULL;
		root->right = NULL;
	}
	else if (root->data == element) {
		printf("ERROR: 중복값 입력 불가\n");
	}
	else if (root->data < element) {
		root->right = add(root->right, element); // 재귀함수 사용
	}
	else if (root->data > element) {
		root->left = add(root->left, element);
	}

	return root;
}

// 삭제
void removeElement(BinNode* node, int element) {
    if (node == NULL) { // 비어있는 트리라면
        printf("ERROR : 트리가 비어있음\n");
        return;
    }

    // 삭제할 노드 찾기
    BinNode* curr = node; // 삭제할 노드를 담아줄 변수
    BinNode* parent = NULL; // 부모를 담아줄 변수
    BinNode* child = NULL; // 자식을 담아줄 변수

    while (curr != NULL) {
        if (curr->data < element) { // 현재 노드보다 삭제하고자 하는 요소가 더 크다면
            parent = curr;
            curr = curr->right; // 오른쪽에서 계속 진행
        }
        else if (curr->data > element) { // 현재 노드보다 삭제하고자 하는 요소가 더 작다면
            parent = curr;
            curr = curr->left;
        }
        else { // 찾았다면
            break;
        }
    }

    // 삭제하고자 하는 노드를 찾지 못했다면 curr 에는 NULL값이 들어있다.
    if (curr == NULL) {
        printf("ERROR : 요소 없음"); // 삭제 실패
        return;
    }

    // 삭제하고자 하는 노드가 리프노드 라면
    if (curr->left == NULL && curr->right == NULL) { // 리프노드라면
        if (parent == NULL) { // 리프노드면서 루트라면
            node = NULL;
        }
        else { // 루트는 아닐 경우
            if (parent->right == curr) {
                parent->right = NULL;
            }
            else {
                parent->left = NULL;
            }
        }
    }

    // 만일 삭제하고자 하는 노드가 자식 1개를 갖고 있다면
    else if (curr->left == NULL || curr->right == NULL) {
        if (curr->left != NULL) { // 삭제할 노드가 왼쪽 자식을 가진 경우
            child = curr->left;
        }
        else { // 오른쪽 자식이라면
            child = curr->right;
        }

        if (parent == NULL) { // 자식이 하나인 루트를 삭제하고자 할 경우
            node = child;
        }
        else {
            if (curr == parent->right) { // 부모의 오른쪽 자식이라면
                parent->right = child;
            }
            else { // 왼쪽 자식이라면
                parent->left = child;
            }
        }
    }

    // 삭제하고자 하는 노드가 자식 2개를 2개를 갖고 있다면
    else {
        BinNode* s_parent = curr; // 계승할 부모노드
        BinNode* s = curr->left; // 계승할 노드

        // 계승할 노드를 찾아서 s 에 담아준다.
        // 왼쪽 서브트리에서 최댓값 찾기
        while (s->right != NULL) {
            s_parent = s;
            s = s->right;
        }
        // while문이 끝나면
        // s에는 계승할 노드가, s_parent 에는 계승할 노드의 부모가 들어있다.
        // s에 담긴 값을 curr->data에 옮겨준다.
        curr->data = s->data;
        // 계승할 노드의 부모의 자식을 NULL값으로 바꾸어주고
        s_parent->right = NULL;
        curr = s;
    }

    free(curr);
}

// 검색, 반복문
void search(BinNode* root, int element) {
    BinNode* curr = root; // 루트부터 검색 시작
    while (curr != NULL) {
        if (element < curr->data) { // 찾고자 하는 값이 현재 노드보다 작다면
            curr = curr->left; // 왼쪽으로 내려가서 계속 탐색
        }
        else if (element > curr->data) { // 찾고자 하는 값이 현재 노드보다 크다면
            curr = curr->right; // 오른쪽으로 내려가서 계속 탐색
        }
        else { // 같다면
            break;
        }
    }
    // while문이 종료되면, curr에는 내가 찾는 값을 가진 Node
    // 혹은 NULL이 들어가 있을 것이다.
    if (curr == NULL) {
        printf("ERROR: 찾고자 하는 데이터가 없습니다.\n");
        return;
    }
    // 위 if문에 잡히지 않은 건, 내가 검색한 데이터를 찾은 것!
    printf("찾았습니다. %d\n", curr->data);
}



// 검색, 재귀함수
void select_r(BinNode* node, int element) {

    if (node == NULL) { // 방어 코드 작성
        printf("ERROR: 찾고자 하는 데이터가 없습니다.\n");
        return;
    }

    if (element < node->data) { // 찾고자 하는 값이 현재 노드보다 작다면
        select_r(node->left, element);
    }
    else if (element > node->data) { // 찾고자 하는 값이 현재 노드보다 크다면
        select_r(node->right, element);
    }
    else { // 같다면
        printf("찾았습니다. %d\n", node->data);
        return;
    }

}







