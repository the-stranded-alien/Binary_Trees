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
	return (node);
}

void preorder(Node *root) {
	if (root != NULL) {
		cout << root->key << " ";
		preorder(root->left);
		preorder(root->right);
	}
}

// Constructing all possible binary
// trees with given inorder traversal
// stored in an array from arr[start]
// to arr[end]. Function returns a
// vector of trees.

vector<Node *> getTrees(int arr[], int start, int end) {
	vector<Node *> trees;
	if (start > end) {
		trees.push_back(NULL);
		return trees;
	}
	for (int i = start; i <= end; i++) {
		vector<Node *> leftTrees = getTrees(arr, start, i - 1);
		vector<Node *> rightTrees = getTrees(arr, i + 1, end);
		for (int j = 0; j < leftTrees.size(); j++) {
			for (int k = 0; k < rightTrees.size(); k++) {
				Node *node = newNode(arr[i]);
				node->left = leftTrees[j];
				node->right = rightTrees[k];
				trees.push_back(node);
			}
		}
	}
	return trees;
}

int main() {
#ifndef IO
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int in[] = {4, 5, 7};
	int n = sizeof(in) / sizeof(in[0]);
	vector<Node *> trees = getTrees(in, 0, n - 1);

	for (int i = 0; i < trees.size(); i++) {
		preorder(trees[i]);
		cout << endl;
	}
	return 0;
}