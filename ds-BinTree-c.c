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

// �������Ĵ��� 
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

// �������Ŀ��� 
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

// ������������ 
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


// �ݹ飺ǰ����� 
void PreOrder(BTNode* pRoot)
{
	if (pRoot != NULL)
	{
		printf("%c ", pRoot->_data);
		PreOrder(pRoot->_pLeft);
		PreOrder(pRoot->_pRight);
	}
}

// �ݹ飺������� 
void InOrder(BTNode* pRoot)
{
	if (pRoot != NULL)
	{
		InOrder(pRoot->_pLeft);
		printf("%c ", pRoot->_data);
		InOrder(pRoot->_pRight);
	}
}

// �ݹ飺������� 
void PostOrder(BTNode* pRoot)
{
	if (pRoot != NULL)
	{
		PostOrder(pRoot->_pLeft);
		PostOrder(pRoot->_pRight);
		printf("%c ", pRoot->_data);
	}
}

// ������� 
void LevelOrder(BTNode* pRoot)
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q,pRoot);

	while (QueueEmpty(&q) != 0)
	{
		//ȡ��ͷԪ��
		BTNode* p=QueueFront(&q);

		//������Ԫ��
		printf("%c ", p->_data);

		//������Ӵ���,����
		if (p->_pLeft != NULL)
		{
			QueuePush(&q, p->_pLeft);
		}

		//����Һ��Ӵ���,����
		if (p->_pRight != NULL)
		{
			QueuePush(&q, p->_pRight);
		}

		//ɾ����ͷ
		QueuePop(&q);
	}
}

// ��ȡ�������нڵ���� 
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

// ��ȡ�������е�K��ڵ���� 
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

// ��ȡ��������Ҷ�ӽڵ���� 
int GetLeafCount(BTNode* pRoot)
{
	//Ҷ�ӽڵ�û���ӽڵ�
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

// ��ȡ���������(�߶�) 
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

// ���ֵΪx��Ԫ���Ƿ��ڶ������У��ڷ��ظýڵ�ĵ�ַ�����򷵻�NULL 
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

// �������ľ��� 
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

// �ж϶������Ƿ�����ȫ������ 
int BinaryTreeComplete(BTNode* root)
{
	if (root == NULL)
	{
		return 1;
	}

	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);

	//���
	int flag = 0;

	while (QueueEmpty(&q) != 0)
	{
		BTNode* p=QueueFront(&q);

		//ֻ���Һ���û������,�϶�������ȫ������
		if (p->_pLeft == NULL && p->_pRight != NULL)
		{
			return 0;
		}

		//������Һ��Ӷ�����,����ֻ������,����Ľڵ���붼��Ҷ�ӽڵ�
		if ((p->_pLeft != NULL && p->_pRight == NULL) || (p->_pLeft == NULL && p->_pRight == NULL))
		{
			QueuePop(&q);

			//��ýڵ�֮������н�㶼��Ҷ�ӽڵ�
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

	printf("��ʼǰ�����:");
	PreOrder(pRoot);
	printf("\n");

	printf("��ʼ�������:");
	InOrder(pRoot);
	printf("\n");

	printf("��ʼ�������:");
	PostOrder(pRoot);
	printf("\n");

	printf("��ȡ��3��Ľڵ����: %d\n", GetKLevelNodeCount(pRoot,3));

	printf("��ȡ��������������: %d\n",GetBinTreeHeight(pRoot));

	printf("��ʼ�������:");
	LevelOrder(pRoot);
	printf("\n");

	printf("��ʼ����:");
	CopyBinTree(pRoot);
	LevelOrder(CopyBinTree(pRoot));
	printf("\n");

	printf("%p\n", BinaryTreeFind(pRoot, 'C'));

	printf("��ʼ����:");
	Mirror(pRoot);
	LevelOrder(pRoot);
	printf("\n");

	if (BinaryTreeComplete(pRoot) == 0)
	{
		printf("����ź�,�ⲻ��һ����ȫ������~\n");
	}
	else
	{
		printf("��ϲ,����һ����ȫ������~\n");
	}

	Mirror(pRoot);
	if (BinaryTreeComplete(pRoot) == 0)
	{
		printf("����ź�,�ⲻ��һ����ȫ������~\n");
	}
	else
	{
		printf("��ϲ,����һ����ȫ������~\n");
	}
}

int main()
{

	TestBinTree();
	system("pause");
	return 0;
	
}