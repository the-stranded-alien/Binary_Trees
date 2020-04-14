#include<bits/stdc++.h>
using namespace std;

struct Node {
	int key;
	Node *left;
	Node *right;
};

Node *newNode(int data) {
	Node *node = new Node;
	node->key = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void inorder(Node *temp) {
	if(temp == NULL) return;
	inorder(temp->left);
	cout << temp->key << " ";
	inorder(temp->right);
}

void InsertElement (Node *temp, int key) {

	queue<Node*> q;
	q.push(temp);
	// level order traversal until we find an empty stack
	while(!q.empty()) {

		Node *temp = q.front();
		q.pop();

		if(temp->left == NULL) {
			temp->left = newNode(key);
			break;
		} else q.push(temp->left);
	
		if(temp->right == NULL) {
			temp->right = newNode(key);
			break;
		} else q.push(temp->right);
	}
}

int main() {
#ifndef IO
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Node *root = newNode(10);
	root->left = newNode(11);
	root->left->left = newNode(7);
	root->right = newNode(9);
	root->right->left = newNode(15);
	root->right->right = newNode(8);

	cout << "Inorder : ";
	inorder(root);

	InsertElement(root, 12);

	cout << "\nInorder : ";
	inorder(root); 

	return 0;
}