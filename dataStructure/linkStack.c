#include "linkStack.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>



//栈的链式存储
//节点结构体
struct  LinkNode
{
	//只维护指针域
	struct LinkNode *next;
};

struct LStack
{
	struct LinkNode pHeader;	//头节点
	int m_Size;	//栈大小
};


//初始化栈
LinkStack init_LinkStack()
{
	struct LStack * myStack = malloc(sizeof(struct LStack));
	
	if (myStack == NULL)
	{
		return NULL;
	}
	
	myStack->pHeader.next = NULL;
	myStack->m_Size = 0;
	
	return myStack;
}

//入栈
void push_LinkStack(LinkStack stack, void * data)
{
	//本质 头插
	if (stack == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}
	
	struct LStack * myStack = stack;
	
	//取出用户前4个字节
	struct LinkNode * myNode = data;

	//建立节点之间的关系
	myNode->next = myStack->pHeader.next;
	myStack->pHeader.next = myNode;

	//更新栈大小
	myStack->m_Size++;
}

//出栈
void pop_LinkStack(LinkStack stack)
{
	//出栈本质 数组尾删除
	
	if (stack == NULL)
	{
		return;
	}
	struct LStack * myStack = stack;
	
	if (myStack->m_Size == 0)
	{
		return;
	}
	
	//创建指向第一个节点指针
	struct LinkNode * pFirst = myStack->pHeader.next;
	
	//更新节点指向
	myStack->pHeader.next = pFirst->next;
	
	//更新栈大小
	myStack->m_Size--;
}


//返回栈顶
void * top_LinkStack(LinkStack stack)
{
	//本质 返回数组的最后一个元素
	
	if (stack == NULL)
	{
		return NULL;
	}
	
	struct LStack * myStack = stack;
	
	if (myStack->m_Size == 0)
	{
		return NULL;
	}
	
	return myStack->pHeader.next;
}

//返回栈大小
int size_LinkStack(LinkStack stack)
{
	if (stack == NULL)
	{
		return -1;
	}
	struct LStack * myStack = stack;
	return myStack->m_Size;
}

//判断栈是否为空
int isEmpty_LinkStack(LinkStack stack)
{
	if (stack == NULL)
	{
		return -1;	//传入空指针 返回真 栈也是空
	}

	struct LStack * myStack = stack;
	
	if (myStack->m_Size == 0)
	{
		return 1;	//1代表真，栈确实为空
	}
	
	return 0;	//不为空 假
}

//销毁
void destroy_LinkStack(LinkStack stack)
{
	if (stack == NULL)
	{
		return;
	}
	free(stack);
	stack = NULL;
}




//测试栈
struct Person
{
	//struct LinkNode node;
	int *node;
	char name[64];
	int age;
};

void test()
{
	//创建栈
	LinkStack myStack = init_LinkStack();
	
	//创建数据
	struct Person p1 = {NULL, "aaa", 11};
	struct Person p2 = {NULL, "bbb", 22};
	struct Person p3 = {NULL, "ccc", 33};
	struct Person p4 = {NULL, "ddd", 44};
	struct Person p5 = {NULL, "eee", 55};
	
	//入栈
	push_LinkStack(myStack, &p1);
	push_LinkStack(myStack, &p2);
	push_LinkStack(myStack, &p3);
	push_LinkStack(myStack, &p4);
	push_LinkStack(myStack, &p5);
	
	printf("栈的大小为：%d\n", size_LinkStack(myStack));
	
	while (isEmpty_LinkStack(myStack) == 0)	//栈不为空 开始查看栈顶 并且出栈
	{
		struct Person * pTop = top_LinkStack(myStack);
		printf("链式存储：：：栈顶元素-姓名：%s	年龄：%d\n", pTop->name, pTop->age);
		
		//出栈
		pop_LinkStack(myStack);
	}
	
	printf("栈的大小为：%d\n", size_LinkStack(myStack));
	
	destroy_LinkStack(myStack);
}