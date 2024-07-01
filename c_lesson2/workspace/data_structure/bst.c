#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data; // �������� �����Ͱ� ����� ��� ����
	struct Node* left; // ���� �ڽ��� ������ ������ ����
	struct Node* right; // ������ �ڽ��� ������ ������ ����
}BinNode;

// show() - ����, ����, ����
// ���� ��ȸ: ���� �湮, ���� �ڽ�, ������ �ڽ�
void proShow(BinNode* node);

// ���� ��ȸ: ���� �ڽ�, ���� �湮, ������ �ڽ�
// ����Ž��Ʈ������ ���� ��ȸ�� ����ϸ� ���ĵ� ������� Ž���� �� �ִ�.
void inShow(BinNode* node);

// ���� ��ȸ: ���� �ڽ�, ������ �ڽ�, ���� �湮
void postShow(BinNode* node);

// �߰�
BinNode* add(BinNode* root, int element);

// ����
void removeElement(BinNode* node, int element);

// �˻�, �ݺ���
void search(BinNode* root, int element);

// �˻�, ����Լ�
void select_r(BinNode* node, int element);

int main() {
	BinNode* root;
	root = NULL;
	root = add(root, 10); // ���ʿ� ���Ե� �����Ͱ� root ��尡 �ȴ�.

	add(root, 5);
	add(root, 7);
	add(root, 15);
	add(root, 13);
	printf("���� ��ȸ: ");
	proShow(root);
	printf("\n");
	printf("���� ��ȸ: ");
	inShow(root);
	printf("\n");
	printf("���� ��ȸ: ");
	postShow(root);
	printf("\n");

	removeElement(root, 5);
	inShow(root);
	printf("\n");
    search(root, 10);
    select_r(root, 100);

	return 0;
}

// ���� ��ȸ: ���� �湮, ���� �ڽ�, ������ �ڽ�
void proShow(BinNode* node) {
	if (node != NULL) {
		printf("[%d] ", node->data);
		proShow(node->left);
		proShow(node->right);
	}
}

// ���� ��ȸ: ���� �ڽ�, ���� �湮, ������ �ڽ�
void inShow(BinNode* node) {
	if (node != NULL) {
		inShow(node->left);
		printf("[%d] ", node->data);
		inShow(node->right);
	}
}

// ���� ��ȸ: ���� �ڽ�, ������ �ڽ�, ���� �湮
void postShow(BinNode* node) {
	if (node != NULL) {
		postShow(node->left);
		postShow(node->right);
		printf("[%d] ", node->data);
	}
}


// �߰�
BinNode* add(BinNode* root, int element) {
	if (root == NULL) { // ����ִ� Ʈ�����
		// �߰��ϰ��� �ϴ� ��尡 root ��尡 �� ���̴�.
		root = (BinNode*)malloc(sizeof(BinNode));
		root->data = element;
		root->left = NULL;
		root->right = NULL;
	}
	else if (root->data == element) {
		printf("ERROR: �ߺ��� �Է� �Ұ�\n");
	}
	else if (root->data < element) {
		root->right = add(root->right, element); // ����Լ� ���
	}
	else if (root->data > element) {
		root->left = add(root->left, element);
	}

	return root;
}

// ����
void removeElement(BinNode* node, int element) {
    if (node == NULL) { // ����ִ� Ʈ�����
        printf("ERROR : Ʈ���� �������\n");
        return;
    }

    // ������ ��� ã��
    BinNode* curr = node; // ������ ��带 ����� ����
    BinNode* parent = NULL; // �θ� ����� ����
    BinNode* child = NULL; // �ڽ��� ����� ����

    while (curr != NULL) {
        if (curr->data < element) { // ���� ��庸�� �����ϰ��� �ϴ� ��Ұ� �� ũ�ٸ�
            parent = curr;
            curr = curr->right; // �����ʿ��� ��� ����
        }
        else if (curr->data > element) { // ���� ��庸�� �����ϰ��� �ϴ� ��Ұ� �� �۴ٸ�
            parent = curr;
            curr = curr->left;
        }
        else { // ã�Ҵٸ�
            break;
        }
    }

    // �����ϰ��� �ϴ� ��带 ã�� ���ߴٸ� curr ���� NULL���� ����ִ�.
    if (curr == NULL) {
        printf("ERROR : ��� ����"); // ���� ����
        return;
    }

    // �����ϰ��� �ϴ� ��尡 ������� ���
    if (curr->left == NULL && curr->right == NULL) { // ���������
        if (parent == NULL) { // �������鼭 ��Ʈ���
            node = NULL;
        }
        else { // ��Ʈ�� �ƴ� ���
            if (parent->right == curr) {
                parent->right = NULL;
            }
            else {
                parent->left = NULL;
            }
        }
    }

    // ���� �����ϰ��� �ϴ� ��尡 �ڽ� 1���� ���� �ִٸ�
    else if (curr->left == NULL || curr->right == NULL) {
        if (curr->left != NULL) { // ������ ��尡 ���� �ڽ��� ���� ���
            child = curr->left;
        }
        else { // ������ �ڽ��̶��
            child = curr->right;
        }

        if (parent == NULL) { // �ڽ��� �ϳ��� ��Ʈ�� �����ϰ��� �� ���
            node = child;
        }
        else {
            if (curr == parent->right) { // �θ��� ������ �ڽ��̶��
                parent->right = child;
            }
            else { // ���� �ڽ��̶��
                parent->left = child;
            }
        }
    }

    // �����ϰ��� �ϴ� ��尡 �ڽ� 2���� 2���� ���� �ִٸ�
    else {
        BinNode* s_parent = curr; // ����� �θ���
        BinNode* s = curr->left; // ����� ���

        // ����� ��带 ã�Ƽ� s �� ����ش�.
        // ���� ����Ʈ������ �ִ� ã��
        while (s->right != NULL) {
            s_parent = s;
            s = s->right;
        }
        // while���� ������
        // s���� ����� ��尡, s_parent ���� ����� ����� �θ� ����ִ�.
        // s�� ��� ���� curr->data�� �Ű��ش�.
        curr->data = s->data;
        // ����� ����� �θ��� �ڽ��� NULL������ �ٲپ��ְ�
        s_parent->right = NULL;
        curr = s;
    }

    free(curr);
}

// �˻�, �ݺ���
void search(BinNode* root, int element) {
    BinNode* curr = root; // ��Ʈ���� �˻� ����
    while (curr != NULL) {
        if (element < curr->data) { // ã���� �ϴ� ���� ���� ��庸�� �۴ٸ�
            curr = curr->left; // �������� �������� ��� Ž��
        }
        else if (element > curr->data) { // ã���� �ϴ� ���� ���� ��庸�� ũ�ٸ�
            curr = curr->right; // ���������� �������� ��� Ž��
        }
        else { // ���ٸ�
            break;
        }
    }
    // while���� ����Ǹ�, curr���� ���� ã�� ���� ���� Node
    // Ȥ�� NULL�� �� ���� ���̴�.
    if (curr == NULL) {
        printf("ERROR: ã���� �ϴ� �����Ͱ� �����ϴ�.\n");
        return;
    }
    // �� if���� ������ ���� ��, ���� �˻��� �����͸� ã�� ��!
    printf("ã�ҽ��ϴ�. %d\n", curr->data);
}



// �˻�, ����Լ�
void select_r(BinNode* node, int element) {

    if (node == NULL) { // ��� �ڵ� �ۼ�
        printf("ERROR: ã���� �ϴ� �����Ͱ� �����ϴ�.\n");
        return;
    }

    if (element < node->data) { // ã���� �ϴ� ���� ���� ��庸�� �۴ٸ�
        select_r(node->left, element);
    }
    else if (element > node->data) { // ã���� �ϴ� ���� ���� ��庸�� ũ�ٸ�
        select_r(node->right, element);
    }
    else { // ���ٸ�
        printf("ã�ҽ��ϴ�. %d\n", node->data);
        return;
    }

}







