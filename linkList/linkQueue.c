#include "linkQueue.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//节点结构体
struct QueueNode
{
	struct QueueNode * next;

};

//链表的结构体 --- 队列
struct LQueue
{
	struct QueueNode pHeader; //头节点
	int m_Size; //队列的大小
	struct QueueNode * pTail; //记录尾节点的指针
};


//初始化队列
LinkQueue init_LinkQueue()
{
	struct LQueue * myQueue = malloc(sizeof(struct LQueue));
	if (myQueue == NULL)
	{
		return NULL;
	}

	myQueue->m_Size = 0;
	myQueue->pHeader.next = NULL;
	myQueue->pTail = &myQueue->pHeader; //尾节点开始指向的就是头节点
	return myQueue;
}
//入队
void push_LinkQueue(LinkQueue queue, void * data)
{
	//等价于 尾插
	if (queue == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}

	struct LQueue * myQueue = queue;

	struct QueueNode * myNode = data; 


	//更改指针指向
	myQueue->pTail->next = myNode;
	myNode->next = NULL;
	//更新尾节点
	myQueue->pTail = myNode;

	//更新队列大小
	myQueue->m_Size++;

}
//出队
void pop_LinkQueue(LinkQueue queue)
{
	//等价于 头删 

	if (queue == NULL)
	{
		return;
	}
	struct LQueue * myQueue = queue;

	if (myQueue->m_Size == 0)
	{
		return;
	}

	if (myQueue->m_Size == 1)
	{
		myQueue->pHeader.next = NULL;
		myQueue->pTail = &myQueue->pHeader; //维护尾节点指针
		myQueue->m_Size = 0;
		return;
	}

	//记录第一个节点
	struct QueueNode * pFirst = myQueue->pHeader.next;

	myQueue->pHeader.next = pFirst->next;

	//更新队列大小
	myQueue->m_Size--;

}
//返回队头
void * front_LinkQueue(LinkQueue queue)
{
	if (queue == NULL)
	{
		return NULL;
	}
	struct LQueue * myQueue = queue;

	return myQueue->pHeader.next;

}
//返回队尾
void * back_LinkQueue(LinkQueue queue)
{
	if (queue == NULL)
	{
		return NULL;
	}
	struct LQueue * myQueue = queue;

	return myQueue->pTail;

}
//返回队列大小
int size_LinkQueue(LinkQueue queue)
{
	if (queue == NULL)
	{
		return -1;
	}
	struct LQueue * myQueue = queue;

	return myQueue->m_Size;

}
//判断队列是否为空
int isEmpty_LinkQueue(LinkQueue queue)
{
	if (queue == NULL)
	{
		return -1;
	}
	struct LQueue * myQueue = queue;

	if (myQueue->m_Size == 0)
	{
		return 1;
	}

	return 0;

}
//销毁队列
void destroy_LinkQueue(LinkQueue queue)
{
	if (queue == NULL)
	{
		return;
	}
	free(queue);
	queue = NULL;
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
	LinkQueue myStack = init_LinkQueue();
	
	//创建数据
	struct Person p1 = {NULL, "aaa", 11};
	struct Person p2 = {NULL, "bbb", 22};
	struct Person p3 = {NULL, "ccc", 33};
	struct Person p4 = {NULL, "ddd", 44};
	struct Person p5 = {NULL, "eee", 55};
	
	//入栈
	push_LinkQueue(myStack, &p1);
	push_LinkQueue(myStack, &p2);
	push_LinkQueue(myStack, &p3);
	push_LinkQueue(myStack, &p4);
	push_LinkQueue(myStack, &p5);
	
	printf("队列的大小为：%d\n", size_LinkQueue(myStack));
	
	while (isEmpty_LinkQueue(myStack) == 0)	//栈不为空 开始查看栈顶 并且出栈
	{
		//队头元素
		struct Person * pFront = front_LinkQueue(myStack);
		printf("链式存储：：：队头元素-姓名：%s	年龄：%d\n", pFront->name, pFront->age);

		//队尾元素
		struct Person * pBack = back_LinkQueue(myStack);
		printf("链式存储：：：队尾元素-姓名：%s	年龄：%d\n", pBack->name, pBack->age);
		
		//出队
		pop_LinkQueue(myStack);
	}
	
	printf("栈的大小为：%d\n", size_LinkQueue(myStack));
	
	destroy_LinkQueue(myStack);
}