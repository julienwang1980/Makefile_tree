#include "seqQueue.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "dynamicArray.h"



//初始化队列
SeqQueue init_SeqQueue()
{
	struct dynamicArray * array = init_dynamicArray(MAX);

	return array;
}

//入队
void push_SeqQueue(SeqQueue queue, void * data)
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

	struct dynamicArray * array = queue;

	if (array->m_Size >= MAX)
	{
		return;
	}

	insert_dynamicArray(array, array->m_Size, data);
}
//出队
void pop_SeqQueue(SeqQueue queue)
{
	//等价于  头删除
	if (queue == NULL)
	{
		return;
	}

	struct dynamicArray * array = queue;

	if (array->m_Size <= 0)
	{
		return;
	}
	removeByPos_dynamicArray(array, 0);
}
//返回队头元素
void * front_SeqQueue(SeqQueue queue)
{
	if (queue == NULL)
	{
		return NULL;
	}

	struct dynamicArray * array = queue;

	return array->pAddr[0];

}

//返回队尾元素
void * back_SeqQueue(SeqQueue queue)
{
	if (queue == NULL)
	{
		return NULL;
	}

	struct dynamicArray * array = queue;
	
	return array->pAddr[array->m_Size - 1];

}

//队列大小
int size_SeqQueue(SeqQueue queue)
{
	if (queue == NULL)
	{
		return -1;
	}

	struct dynamicArray * array = queue;

	return array->m_Size;
}

//判断是否为空
int isEmpty_SeqQueue(SeqQueue queue)
{
	if (queue == NULL)
	{
		return -1;
	}

	struct dynamicArray * array = queue;
	if (array->m_Size == 0)
	{
		return 1;
	}

	return 0;
}

//销毁队列
void destroy_SeqQueue(SeqQueue queue)
{

	if (queue == NULL)
	{
		return ;
	}

	destroy_dynamicArray(queue);
	queue = NULL;
}


//队列测试
struct Person
{
	char name[64];
	int age;
};

void seqQueue_test()
{
	//初始化队列
	SeqQueue myQueue = init_SeqQueue();
	
	//准备数据
	struct Person p1 = {"aaa", 11};
	struct Person p2 = {"bbb", 22};
	struct Person p3 = {"ccc", 33};
	struct Person p4 = {"ddd", 44};
	struct Person p5 = {"eee", 55};
	
	//入队
	push_SeqQueue(myQueue, &p1);
	push_SeqQueue(myQueue, &p2);
	push_SeqQueue(myQueue, &p3);
	push_SeqQueue(myQueue, &p4);
	push_SeqQueue(myQueue, &p5);

	//队列大小
	printf("队列大小为：%d\n", size_SeqQueue(myQueue));
	
	//通过循环查看队头 队尾 执行出队
	while (isEmpty_SeqQueue(myQueue) == 0)	//不为空
	{
		struct Person * personFront = front_SeqQueue(myQueue);
		printf("队头元素 姓名：%s	年龄：%d\n", personFront->name, personFront->age);
	
		struct Person * personBack = back_SeqQueue(myQueue);
		printf("队尾元素 姓名：%s	年龄：%d\n", personBack->name, personBack->age);
		
		//出队
		pop_SeqQueue(myQueue);
	}
	
	//队列大小
	printf("队列大小为：%d\n", size_SeqQueue(myQueue));
	
	destroy_SeqQueue(myQueue);
}