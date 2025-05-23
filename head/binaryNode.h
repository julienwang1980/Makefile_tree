#define _BINARY_NODE_H_
#ifndef _BINARY_NODE_H_

struct BinaryNode
{
	char ch; //数据域

	struct BinaryNode * lChild;//左子树指针

	struct BinaryNode * rChild; //右子树指针
};


//获取叶子数量
void calculateLeafNum( struct BinaryNode * root , int *p );

//获取树的高度
int getTreeHeight(struct BinaryNode * root);

//拷贝二叉树
struct BinaryNode * copyTree(struct BinaryNode * root);

//显示树
void showTree(struct BinaryNode * root);

//释放树
void freeTree(struct BinaryNode * root);


void test();

#endif
