/*
  Linked List 를 이용하여 구현.
  순회 순서
  전위 루트 좌 우
  중위 좌 루트 우
  후위 좌 우 루트
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int N;

struct Node {
	char node = 0;
	Node* left = NULL;
	Node* right = NULL;
};

Node arr[27];

void preorder(Node temp) {
	cout << temp.node;
	if (temp.left != NULL) {
		Node l_node = *(temp.left);
		preorder(l_node);
	}
	if (temp.right != NULL) {
		Node r_node = *(temp.right);
		preorder(r_node);
	}
	return;
}

void inorder(Node temp) {
	if (temp.left != NULL) {
		Node l_node = *(temp.left);
		inorder(l_node);
	}
	cout << temp.node;
	if (temp.right != NULL) {
		Node r_node = *(temp.right);
		inorder(r_node);
	}
	return;
}

void postorder(Node temp) {
	if (temp.left != NULL) {
		Node l_node = *(temp.left);
		postorder(l_node);
	}
	if (temp.right != NULL) {
		Node r_node = *(temp.right);
		postorder(r_node);
	}
	cout << temp.node;
	return;
}

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++) {
		char ch1, ch2, ch3;
		cin >> ch1 >> ch2 >> ch3;
        arr[ch1 - 65].node = ch1;
		if(ch2 != '.') arr[ch1 - 65].left = &arr[ch2 - 65];
		if (ch3 != '.') arr[ch1 - 65].right = &arr[ch3 - 65];
	}

	preorder(arr[0]); cout << "\n";
	inorder(arr[0]); cout << "\n";
	postorder(arr[0]);

	return 0;
}
