#ifndef __BinTree_ 
#define __BinTree_

typedef struct tTreeNode {
	char data;
	struct tTreeNode *left, *right;
} TreeNode;

TreeNode* MakeBT(TreeNode *left, char data, TreeNode *right);
void FreeBT(TreeNode *root, int level); // deallocate all nodes
void Inorder(TreeNode *root, int level); // inorder traversal
void Preorder(TreeNode *root, int level); // preorder traversal
void Postorder(TreeNode *root, int level); // postorder traversal
void PrintTab(int level);

#endif