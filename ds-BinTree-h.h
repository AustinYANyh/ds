#pragma once

//分析顺序存储二叉树的优缺点


typedef char BTDataType;

typedef struct BTNode
{
	struct BTNode* _pLeft;
	struct BTNode* _pRight;
	BTDataType _data;
}BTNode;


// 二叉树的创建 
BTNode* CreateBinTree(BTDataType* array, int size,  BTDataType invalid);

// 二叉树的拷贝 
BTNode* CopyBinTree(BTNode* pRoot);

// 二叉树的销毁 
void DestroyBinTree(BTNode** pRoot);

// 递归：前序遍历 
void PreOrder(BTNode* pRoot);

// 递归：中序遍历 
void InOrder(BTNode* pRoot);

// 递归：后序遍历 
void PostOrder(BTNode* pRoot);

// 层序遍历 
void LevelOrder(BTNode* pRoot);

// 获取二叉树中节点个数 
int GetBinTreeSize(BTNode* pRoot);

// 获取二叉树中第K层节点个数 
int GetKLevelNodeCount(BTNode* pRoot, int K);

// 获取二叉树中叶子节点个数 
int GetLeafCount(BTNode* pRoot);

// 获取二叉树深度(高度) 
int GetBinTreeHeight(BTNode* pRoot);

// 检测值为x的元素是否在二叉树中，在返回该节点的地址，否则返回NULL 
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);

// 二叉树的镜像 
void Mirror(BTNode* pRoot);

// 判断二叉树是否是完全二叉树 
int BinaryTreeComplete(BTNode* root);