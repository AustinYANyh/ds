#include "BinTree.h"
#include "queue.h"
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <string.h>

BTNode* BuyNode(BTDataType data)
{
	BTNode* pNewNode = (BTNode*)malloc(sizeof(BTNode));
	if (pNewNode == NULL)
	{
		assert(0);
	}
	pNewNode->_data = data;
	pNewNode->_pLeft = NULL;
	pNewNode->_pRight = NULL;
	return pNewNode;
}

void swap(BTDataType* a, BTDataType* b)
{
	BTDataType tmp = *a;
	*a = *b;
	*b = tmp;
}

// 二叉树的创建 
BTNode* _CreateBinTree(BTDataType* array, int size, int* index, BTDataType invalid)
{
	BTNode* pRoot = NULL;
	if (*index<size && array[*index]!='#')
	{
		pRoot = BuyNode(array[*index]);
		(*index)++;

		pRoot->_pLeft = _CreateBinTree(array, size, index, invalid);
		(*index)++;

		pRoot->_pRight = _CreateBinTree(array, size, index, invalid);
	}
	return pRoot;
}

BTNode* CreateBinTree(BTDataType* array, int size,  BTDataType invalid)
{
	int index = 0;
	return _CreateBinTree(array, size, &index, invalid);
}

// 二叉树的拷贝 
BTNode* CopyBinTree(BTNode* pRoot)
{
	if (pRoot == NULL)
	{
		return NULL;
	}

	BTNode* newLeft = NULL;
	BTNode* newRight = NULL;
	BTNode* newNode = BuyNode(pRoot->_data);

	if (pRoot->_pLeft != NULL)
	{
		newLeft=CopyBinTree(pRoot->_pLeft);
	}
	else
	{
		newLeft = NULL;
	}

	if (pRoot->_pRight != NULL)
	{
		newRight = CopyBinTree(pRoot->_pRight);
	}
	else
	{
		newRight = NULL;
	}
	newNode->_pLeft = newLeft;
	newNode->_pRight = newRight;
	return newNode;
}

// 二叉树的销毁 
void DestroyBinTree(BTNode** pRoot)
{
	if (*pRoot != NULL)
	{
		DestroyBinTree((*pRoot)->_pLeft);
		DestroyBinTree((*pRoot)->_pRight);
		free(pRoot);
		*pRoot = NULL;
	}
}


// 递归：前序遍历 
void PreOrder(BTNode* pRoot)
{
	if (pRoot != NULL)
	{
		printf("%c ", pRoot->_data);
		PreOrder(pRoot->_pLeft);
		PreOrder(pRoot->_pRight);
	}
}

// 递归：中序遍历 
void InOrder(BTNode* pRoot)
{
	if (pRoot != NULL)
	{
		InOrder(pRoot->_pLeft);
		printf("%c ", pRoot->_data);
		InOrder(pRoot->_pRight);
	}
}

// 递归：后序遍历 
void PostOrder(BTNode* pRoot)
{
	if (pRoot != NULL)
	{
		PostOrder(pRoot->_pLeft);
		PostOrder(pRoot->_pRight);
		printf("%c ", pRoot->_data);
	}
}

// 层序遍历 
void LevelOrder(BTNode* pRoot)
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q,pRoot);

	while (QueueEmpty(&q) != 0)
	{
		//取队头元素
		BTNode* p=QueueFront(&q);

		//遍历该元素
		printf("%c ", p->_data);

		//如果左孩子存在,保存
		if (p->_pLeft != NULL)
		{
			QueuePush(&q, p->_pLeft);
		}

		//如果右孩子存在,保存
		if (p->_pRight != NULL)
		{
			QueuePush(&q, p->_pRight);
		}

		//删除队头
		QueuePop(&q);
	}
}

// 获取二叉树中节点个数 
int GetBinTreeSize(BTNode* pRoot)
{
	if (pRoot == NULL)
	{
		return 0;
	}
	else
	{
		return GetBinTreeSize(pRoot->_pLeft) + GetBinTreeSize(pRoot->_pRight) + 1;
	}
}

// 获取二叉树中第K层节点个数 
int GetKLevelNodeCount(BTNode* pRoot, int K)
{
	if (pRoot == NULL)
	{
		return 0;
	}
	if (pRoot->_pLeft == NULL && pRoot->_pRight == NULL)
	{
		return 1;
	}
	else
	{
		return GetKLevelNodeCount(pRoot->_pLeft, K - 1) + GetKLevelNodeCount(pRoot->_pRight, K - 1);
	}
}

// 获取二叉树中叶子节点个数 
int GetLeafCount(BTNode* pRoot)
{
	//叶子节点没有子节点
	if (pRoot == NULL)
	{
		return 0;
	}
	if (pRoot->_pLeft == NULL && pRoot->_pRight == NULL)
	{
		return 1;
	}
	else
	{
		return GetLeafCount(pRoot->_pLeft) + GetLeafCount(pRoot->_pRight);
	}
}

// 获取二叉树深度(高度) 
int GetBinTreeHeight(BTNode* pRoot)
{
	if (pRoot == NULL)
	{
		return 0;
	}
	if (pRoot->_pLeft == NULL && pRoot->_pRight == NULL)
	{
		return 1;
	}
	else
	{
		int t1 = GetBinTreeHeight(pRoot->_pLeft);
		int t2 = GetBinTreeHeight(pRoot->_pRight);
		if (t1 < t2)
		{
			return t2 + 1;
		}
		else
		{
			return t1 + 1;
		}
	}
}

// 检测值为x的元素是否在二叉树中，在返回该节点的地址，否则返回NULL 
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->_data == x)
	{
		return root;
	}

	BinaryTreeFind(root->_pLeft,x);
	BinaryTreeFind(root->_pRight, x);
}

// 二叉树的镜像 
void Mirror(BTNode* pRoot)
{
	if (pRoot != NULL)
	{
		BTNode* tmp = pRoot->_pLeft;
		pRoot->_pLeft = pRoot->_pRight;
		pRoot->_pRight = tmp;

		Mirror(pRoot->_pLeft);
		Mirror(pRoot->_pRight);
	}
}

// 判断二叉树是否是完全二叉树 
int BinaryTreeComplete(BTNode* root)
{
	if (root == NULL)
	{
		return 1;
	}

	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);

	//标记
	int flag = 0;

	while (QueueEmpty(&q) != 0)
	{
		BTNode* p=QueueFront(&q);

		//只有右孩子没有左孩子,肯定不是完全二叉树
		if (p->_pLeft == NULL && p->_pRight != NULL)
		{
			return 0;
		}

		//如果左右孩子都不在,或者只有左孩子,后面的节点必须都是叶子节点
		if ((p->_pLeft != NULL && p->_pRight == NULL) || (p->_pLeft == NULL && p->_pRight == NULL))
		{
			QueuePop(&q);

			//则该节点之后的所有结点都是叶子节点
			while (QueueEmpty(&q)!=0)
			{
				BTNode* p = QueueFront(&q);

				if (p->_pLeft == NULL && p->_pRight == NULL)
				{
					QueuePop(&q);
				}
				else
				{
					return 0;
				}
			}
			return 1;
		}


		if (p->_pLeft!=NULL)
		{
			QueuePush(&q, p->_pLeft);
		}
		if (p->_pRight != NULL)
		{
			QueuePush(&q, p->_pRight);
		}
		QueuePop(&q);
	}
	return 1;
}

void TestBinTree()
{
	char a[] = "ABD###CE##F";
	int index = 0;
	BTNode* pRoot=CreateBinTree(a, strlen(a), &index, '#');

	printf("开始前序遍历:");
	PreOrder(pRoot);
	printf("\n");

	printf("开始中序遍历:");
	InOrder(pRoot);
	printf("\n");

	printf("开始后序遍历:");
	PostOrder(pRoot);
	printf("\n");

	printf("获取第3层的节点个数: %d\n", GetKLevelNodeCount(pRoot,3));

	printf("获取二叉树的最大深度: %d\n",GetBinTreeHeight(pRoot));

	printf("开始层序遍历:");
	LevelOrder(pRoot);
	printf("\n");

	printf("开始拷贝:");
	CopyBinTree(pRoot);
	LevelOrder(CopyBinTree(pRoot));
	printf("\n");

	printf("%p\n", BinaryTreeFind(pRoot, 'C'));

	printf("开始镜像:");
	Mirror(pRoot);
	LevelOrder(pRoot);
	printf("\n");

	if (BinaryTreeComplete(pRoot) == 0)
	{
		printf("如此遗憾,这不是一棵完全二叉树~\n");
	}
	else
	{
		printf("恭喜,这是一棵完全二叉树~\n");
	}

	Mirror(pRoot);
	if (BinaryTreeComplete(pRoot) == 0)
	{
		printf("如此遗憾,这不是一棵完全二叉树~\n");
	}
	else
	{
		printf("恭喜,这是一棵完全二叉树~\n");
	}
}

int main()
{

	TestBinTree();
	system("pause");
	return 0;
	
}