#include<bits/stdc++.h>
using namespace std;

int search (int arr[], int x, int n) {
	for (int i = 0; i < n; i++) if (arr[i] == x) return i;
	return -1;
}

void PostorderFromPreorderAndInorder(int inorder[], int preorder[], int n) {
	int root = search(inorder, preorder[0], n);
	if (root != 0) PostorderFromPreorderAndInorder(inorder, preorder + 1, root);
	if (root != n - 1) PostorderFromPreorderAndInorder(inorder + root + 1, preorder + root + 1, n - root - 1);
	cout << preorder[0] << " ";
}

int main() {
#ifndef IO
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int in[] = {4, 2, 5, 1, 3, 6};
	int pre[] = {1, 2, 4, 5, 3, 6};
	int n = sizeof(in) / sizeof(in[0]);
	cout << "Postorder Traversal " << endl;
	PostorderFromPreorderAndInorder(in, pre, n);
	return 0;
}