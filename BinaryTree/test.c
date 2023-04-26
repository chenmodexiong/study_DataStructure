#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>



typedef int DateType;

typedef struct BTNode
{
	DateType date;
	struct BTNode* left;
	struct BTNode* right;
}BTNode;

BTNode* BuyNode(DateType x)
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	if (newnode == NULL)
	{
		perror("malloc fail\n");
		return NULL;
	}
	newnode->date = x;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

//前序遍历
void PreOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	
	printf("%d ", root->date);
	PreOrder(root->left);
	PreOrder(root->right);
}

//中序遍历
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	InOrder(root->left);
	printf("%d ", root->date);
	InOrder(root->right);
}

//后序遍历
void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->date);
}

//求二叉树节点个数(用全局变量有问题的写法)
// 
//size_t size = 0;
//size_t TreeSize(BTNode* root)
//{
//	if (root == NULL)
//		return 0;
//	size++;
//	TreeSize(root->left);
//	TreeSize(root->right);
//	return size;
//}


//计算二叉树节点个数
size_t TreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	
	return TreeSize(root->left) + TreeSize(root->right) + 1;
}

//计算二叉树的深度(有一定问题的写法)
//size_t TreeHeight(BTNode* root)
//{
//	if (root == NULL)
//		return 0;
//
//	return TreeHeight(root->left) > TreeHeight(root->right)
//		? TreeHeight(root->left) + 1 : TreeHeight(root->right) + 1;
//}

//计算二叉树的深度
size_t TreeHeight(BTNode* root)
{
	if (root == NULL)
		return 0;

	size_t left_height = TreeHeight(root->left);
	size_t right_height = TreeHeight(root->right);
	return left_height > right_height ? left_height + 1 : right_height + 1;
}



int main()
{
	//手戳一个二叉树
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);
	BTNode* node7 = BuyNode(7);

	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;
	node6->left = node7;

	PreOrder(node1);
	printf("\n");
	InOrder(node1);
	printf("\n");
	PostOrder(node1);
	printf("\n");
	printf("%zd", TreeSize(node1));
	printf("\n");
	printf("%zd", TreeHeight(node1));


	return 0;
}





