#pragma once

//����˳��洢����������ȱ��


typedef char BTDataType;

typedef struct BTNode
{
	struct BTNode* _pLeft;
	struct BTNode* _pRight;
	BTDataType _data;
}BTNode;


// �������Ĵ��� 
BTNode* CreateBinTree(BTDataType* array, int size,  BTDataType invalid);

// �������Ŀ��� 
BTNode* CopyBinTree(BTNode* pRoot);

// ������������ 
void DestroyBinTree(BTNode** pRoot);

// �ݹ飺ǰ����� 
void PreOrder(BTNode* pRoot);

// �ݹ飺������� 
void InOrder(BTNode* pRoot);

// �ݹ飺������� 
void PostOrder(BTNode* pRoot);

// ������� 
void LevelOrder(BTNode* pRoot);

// ��ȡ�������нڵ���� 
int GetBinTreeSize(BTNode* pRoot);

// ��ȡ�������е�K��ڵ���� 
int GetKLevelNodeCount(BTNode* pRoot, int K);

// ��ȡ��������Ҷ�ӽڵ���� 
int GetLeafCount(BTNode* pRoot);

// ��ȡ���������(�߶�) 
int GetBinTreeHeight(BTNode* pRoot);

// ���ֵΪx��Ԫ���Ƿ��ڶ������У��ڷ��ظýڵ�ĵ�ַ�����򷵻�NULL 
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);

// �������ľ��� 
void Mirror(BTNode* pRoot);

// �ж϶������Ƿ�����ȫ������ 
int BinaryTreeComplete(BTNode* root);