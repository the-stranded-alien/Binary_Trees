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

void InorderTraversal(Node *temp) {
	if (temp == NULL) return;
	InorderTraversal(temp->left);
	cout << temp->key << " ";
	InorderTraversal(temp->right);
}

void deleteDeepest(Node *root, Node *deepest_node) {
	queue<Node *> q;
	q.push(root);

	// Level order traversal until last node
	Node *temp;
	while (!q.empty()) {
		temp = q.front();
		q.pop();
		if (temp == deepest_node) {
			temp = NULL;
			delete(deepest_node);
			return;
		}

		if (temp->right) {
			if (temp->right == deepest_node) {
				temp->right = NULL;
				delete(deepest_node);
				return;
			} else q.push(temp->right);
		}

		if (temp->left) {
			if (temp->left == deepest_node) {
				temp->left = NULL;
				delete(deepest_node);
				return;
			} else q.push(temp->left);
		}
	}
}

Node *deleteElement(Node *root, int key_to_del) {

	// Empty Tree
	if (root == NULL) return NULL;

	//Tree with only one node.
	if (root->left == NULL && root->right == NULL) {
		if (root->key == key_to_del) return NULL;
		else return root;
	}

	queue<Node*> q;
	q.push(root);

	Node *temp;
	Node *key_node = NULL;

	// Level order traversal to find deepest node (temp)
	// and node to be deleted (key_node)
	while (!q.empty()) {
		temp = q.front();
		q.pop();
		if (temp->key == key_to_del) key_node = temp;
		if (temp->left) q.push(temp->left);
		if (temp->right) q.push(temp->right);
	}

	if (key_node != NULL) {
		int x = temp->key;
		deleteDeepest(root, temp);
		key_node->key = x;
	}
	return root;
}


int main()
{
#ifndef IO
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	Node *root = newNode(10);
	root->left = newNode(11);
	root->left->left = newNode(7);
	root->left->right = newNode(12);	
	root->right = newNode(9);
	root->right->left = newNode(15);
	root->right->right = newNode(8);

	cout << "Inorder : ";
	InorderTraversal(root);

	root = deleteElement(root, 12);

	cout << "\nInorder : ";
	InorderTraversal(root);
	return 0;
}