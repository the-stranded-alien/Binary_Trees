#include<bits/stdc++.h>
using namespace std;

// 1. Breadth First Traversals (or Level Order Traversal)
// 2. Depth First Traversals
// 		a. Inorder Traversal(Left : Root : Right)
// 		b. Preorder Traversal(Root : Left : Right)
// 		a. Postorder Traversal(Left : Right : Root)


struct Node {
	int key;
	Node *left;
	Node *right;
	Node(int data) {
		this->key = data;
		left = NULL;
		right = NULL;
	}
};

void Inorder(Node *root) {
	if (root == NULL) return;
	Inorder(root->left);
	cout << root->key << " ";
	Inorder(root->right);
}

void Preorder(Node *root) {
	if (root == NULL) return;
	cout << root->key << " ";
	Preorder(root->left);
	Preorder(root->right);
}

void Postorder(Node *root) {
	if (root == NULL) return;
	Postorder(root->left);
	Postorder(root->right);
	cout << root->key << " ";
}

int main() {
#ifndef IO
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);

	cout << "\nPreorder  : ";
	Preorder(root);
	cout << "\nPostorder : ";
	Postorder(root);
	cout << "\nInorder   : ";
	Inorder(root);
	return 0;
}
