#include<bits/stdc++.h>
using namespace std;

struct Node {
	int key;
	Node *left;
	Node *right;
	Node (int data) {
		this->key = data;
		left = NULL;
		right = NULL;
	}
};

void InorderIter(Node *root) {
	stack<Node *> s;
	Node *curr = root;
	while(curr != NULL || s.empty() == false) {
		while(curr != NULL) {
			s.push(curr);
			curr = curr->left;
		}

		curr = s.top();
		s.pop();
		cout << curr->key << " ";
		curr = curr->right;
	}
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

	InorderIter(root);
	return 0;
}