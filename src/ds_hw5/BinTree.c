#include "BinTree.h"
#include <stdio.h>
#include <malloc.h>

TreeNode* MakeBT(TreeNode *left, char data, TreeNode *right) {
	// allocate memory to root
	TreeNode *root = (TreeNode*)malloc(sizeof(TreeNode));
	// assign parameters to root->left, root->data, root->right each
	root->left = left; 
	root->data = data;
	root->right = right;
}

void FreeBT(TreeNode *root, int level) {
	// if root is null, then leave it
	if (root == NULL);
	// if root is not null, free root and its subtrees
	else {
		// recursion to free left subtree
		FreeBT(root->left, level + 1);
		// recursion to free right subtree
		FreeBT(root->right, level + 1);
		PrintTab(level);
		printf("Deleting %c, level %d\n", root->data, level);
		// free root and set its data to NULL
		free(root);
		root = NULL;
	}
}

void Inorder(TreeNode *root, int level) {
	// if root is null
	if (root == NULL) {
		PrintTab(level);
		printf("Inorder(NULL, %d)\n", level);
	}
	// if root is not null, print in order of left, data, right
	else {
		// use recursion to move to left subtree
		Inorder(root->left, level + 1);
		PrintTab(level);
		// print data, level of root
		printf("Inorder(%c, %d)\n", root->data, level);
		// use recursion to move to right subtree
		Inorder(root->right, level + 1);
	}
}

void Preorder(TreeNode *root, int level) {
	// if root is null
	if (root == NULL) {
		PrintTab(level);
		printf("Preorder(NULL, %d)\n", level);
	}
	// if root is not null, print in order of data, left, right
	else {
		// print data, level of root
		PrintTab(level);
		printf("Preorder(%c, %d)\n", root->data, level);
		// use recursion to move to left subtree
		Preorder(root->left, level + 1);
		// use recursion to move to right subtree
		Preorder(root->right, level + 1);
	}
}

void Postorder(TreeNode *root, int level) {
	// if root is null
	if (root == NULL) {
		PrintTab(level);
		printf("Postorder(NULL, %d)\n", level);
	}
	// if root is not null print in order of left subtree, right subtree, data
	else {
		// use recursion to move to left subtree
		Postorder(root->left, level + 1);
		// use recursion to move to right subtree
		Postorder(root->right, level + 1);
		// print data, level of root
		PrintTab(level);
		printf("Postorder(%c, %d)\n", root->data, level);
	}
}

void PrintTab(int level) {
	// for number of level, print '\t'
	for (int i = 0; i < level; i++)
		putchar('\t');

	return;
}