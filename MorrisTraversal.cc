#include<bits/stdc++.h>
using namespace std;

struct binaryTreeNode {
	int data;
	binaryTreeNode *left;
	binaryTreeNode *right;
};

binaryTreeNode *newNode(int data) {
	binaryTreeNode *node = new binaryTreeNode;
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

// Morris Traversal => Inorder Traversal Without Recursion & Without Stack

void MorrisTraversal(binaryTreeNode *root) {

	binaryTreeNode *current;
	binaryTreeNode *pre;
	if (root == NULL) return;
	current = root;
	while (current != NULL) {
		if (current->left == NULL) {
			cout << current->data << " ";
			current = current->right;
		} else {

			// Inorder Predecessor of current
			pre = current->left;
			while (pre->right != NULL && pre->right != current) pre = pre->right;

			// Current as right child of its inorder predecessor
			if (pre->right == NULL) {
				pre->right = current;
				current = current->left;
			}

			// Revert the changes made, fix the right child of predecessor
			else {
				pre->right = NULL;
				cout << current->data << " ";
				current = current->right;
			}
		}
	}
}

int main() {
#ifndef IO
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	binaryTreeNode *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	MorrisTraversal(root);

	return 0;
}