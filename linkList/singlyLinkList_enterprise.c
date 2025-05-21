#include "singlyLinkList_enterprise.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//节点结构体
struct LinkNode
{
	//只维护指针域
	struct LinkNode *next;
};

//链表结构体
struct LList
{
	struct LinkNode pHeader;	//头节点
	int m_Size;	//链表长度
};


//初始化链表
LinkList init_LinkList()
{
	//分配内存
	struct LList *mylist = malloc(sizeof(struct LList));
	
	if (mylist == NULL)
	{
		return NULL;
	}
	
	//给头节点属性初始化
	mylist->pHeader.next = NULL;
	mylist->m_Size = 0;
	
	return mylist;
}

//插入节点
void insert_LinkList(LinkList list, int pos, void *data)
{
	if (list == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}
	
	//还原链表真实结构体
	struct LList *mylist = list;
	if (pos < 0 || pos > mylist->m_Size)
	{
		//无效位置
		pos = mylist->m_Size;
	}
	
		
	//创建临时节点，通过循环找到待插入位置的前驱节点位置
	struct LinkNode *pCurrent = &mylist->pHeader;
	
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}
	
	//此时pCurrent就是插入位置的前驱节点
	
	//取出用户数据的前4个字节空间
	struct LinkNode * myNode = data;

	//建立节点之间的关系
	myNode->next = pCurrent->next;
	pCurrent->next = myNode;
	
	//更新链表长度
	mylist->m_Size++;
}

//遍历链表
void foreach_LinkList(LinkList list, void (*myPrint)(void *))
{
	if (list == NULL)
	{
		return;
	}
	
	//还原链表真实结构体
	struct LList *mylist = list;
	//指向第一个有真实数据的节点
	struct LinkNode * pCurrent = mylist->pHeader.next;
	
	for (int i = 0; i < mylist->m_Size; i++)
	{
		myPrint(pCurrent);
		pCurrent = pCurrent->next;
	}
}

//删除链表节点，按位置删除
void removeByPos_LinkList(LinkList list, int pos)
{
	if (list == NULL)
	{
		return;
	}
	struct LList *mylist = list;
	if (pos < 0 || pos > mylist->m_Size-1)
	{
		//无效位置
		return;
	}
	
	//找到待删除位置的前驱节点位置
	struct LinkNode *pCurrent = &mylist->pHeader;
	
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}
	
	//pCurrent就是待删除节点的前驱节点位置
	
	//利用指针记录待删除节点
	struct LinkNode *pDel = pCurrent->next;
	
	//更改指针的指向
	pCurrent->next = pDel->next;
	
	//更新链表长度
	mylist->m_Size--;
}

//删除链表节点，按值删除
void removeByValue_LinkList(LinkList list, void *data, int(*myCompare)(void *, void *))
{
	if (list == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}
	
	//还原链表真实结构体
	struct LList *mylist = list;
	
	//创建两个辅助指针变量
	struct LinkNode *pPrev = &mylist->pHeader;
	struct LinkNode *pCurrent = mylist->pHeader.next;
	
	//遍历链表，找用户要删除的数据
	for (int i = 0; i < mylist->m_Size; i++)
	{
		if (myCompare(data, pCurrent))
		{
			//找到要删除的数据了，开始删除
			//更改指针指向
			pPrev->next = pCurrent->next;
			
			//释放节点
			pCurrent->next = NULL;
			
			//更新链表长度
			mylist->m_Size--;
			
			break;
		}
		
		//辅助指针向后移动
		pPrev = pCurrent;
		pCurrent = pCurrent->next;
	}
}

//逆序一个链表
void reverse_LinkList(LinkList list)
{
	
	if (list == NULL)
	{
		return;
	}
	
	struct LinkNode *p = NULL; //准备逆序的节点
	struct LinkNode *prev_p = NULL;//p的前驱
	struct LinkNode *next_p = NULL;//p的后继
	
	//将list还原真实链表结构体
	struct LList *mylist = list;

	//初始化
	prev_p = (struct LinkNode *) &mylist->pHeader;
	p = (struct LinkNode *) mylist->pHeader.next;;

	while (p != NULL)
	{
		//向让next_p 指向p的后继
		next_p = p->next;
		//改变p的后继为p的前驱
		p->next = prev_p;

		//让p的前驱等于p
		prev_p = p;

		//让p等于 原先p的后继 next_p
		p = next_p;
	}

	//先改变原先首元素的地址
	mylist->pHeader.next->next = NULL;

	//将头结点 指向目前的 prev_p 也就是新的首元素地址
	mylist->pHeader.next = prev_p;
}

//返回链表长度
int size_LinkList(LinkList list)
{
	if (list == NULL)
	{
		return -1;
	}
	//void * 别名
	//将list还原真实链表结构体
	struct LList *mylist = list;
	
	return mylist->m_Size;	
}

//清空链表
void clear_LinkList(LinkList list)
{
	if (list == NULL)
	{
		return;
	}
	
	//将list还原真实链表结构体
	struct LList *mylist = list;
	
	struct LinkNode *pCurrent = (struct LinkNode *) mylist->pHeader.next;
	
	for (int i = 0; i < mylist->m_Size; i++)
	{
		//记录下一个节点位置、
		struct LinkNode *pNext = pCurrent->next;
		pCurrent->next = NULL;
		pCurrent = pNext;
	}
	
	mylist->pHeader.next = NULL;
	mylist->m_Size = 0;
}

//销毁列表
void destroy_LinkList(LinkList list)
{
	if (list == NULL)
	{
		return;
	}
	
	//先清空链表，在销毁头节点
	clear_LinkList(list);
	
	free(list);
	list = NULL;
}






//测试链表
struct Person
{
	// struct LinkNode node;
	int *p;
	char name[64];
	int age;
};

//回调函数打印
void printPerson(void *data)
{
	struct Person *person = data;
	printf("姓名：%s	年龄：%d\n", person->name, person->age);
}

//回调函数，删除对比
int ComparePerson(void *data1, void *data2)
{
	struct Person *p1 = data1;
	struct Person *p2 = data2;

	return (strcmp(p1->name, p2->name) == 0) && (p1->age == p2->age);
}

void test()
{
	//初始化链表
	LinkList mylist = init_LinkList();
	
	//创建数据
	struct Person p1 = {NULL, "aaa", 11};
	struct Person p2 = {NULL, "bbb", 22};
	struct Person p3 = {NULL, "ccc", 33};
	struct Person p4 = {NULL, "ddd", 44};
	struct Person p5 = {NULL, "eee", 55};
	
	insert_LinkList(mylist, 0, &p1);
	insert_LinkList(mylist, 0, &p2);
	insert_LinkList(mylist, 1, &p3);
	insert_LinkList(mylist, -1, &p4);
	insert_LinkList(mylist, 0, &p5);

	
	//遍历链表
	//eee bbb ccc aaa ddd
	foreach_LinkList(mylist, printPerson);
	printf("链表长度为：%d\n", size_LinkList(mylist));
	
	//删除节点
	printf("------------------------\n");
	printf("删除bbb之后遍历结果：\n");
	removeByPos_LinkList(mylist, 1);
	foreach_LinkList(mylist, printPerson);
	printf("链表长度为：%d\n", size_LinkList(mylist));
	
	struct Person p = {NULL, "aaa", 11};
	printf("------------------------\n");
	printf("删除aaa之后遍历结果：\n");
	removeByValue_LinkList(mylist, &p, ComparePerson);
	foreach_LinkList(mylist, printPerson);
	printf("链表长度为：%d\n", size_LinkList(mylist));

	//reverse节点
	printf("------------------------\n");
	printf("reverse遍历结果：\n");
	reverse_LinkList(mylist);
	foreach_LinkList(mylist, printPerson);
	printf("链表长度为：%d\n", size_LinkList(mylist));
	
	//清空链表
	printf("------------------------\n");
	printf("清空链表之后遍历结果\n");
	clear_LinkList(mylist);
	foreach_LinkList(mylist, printPerson);
	printf("链表长度为：%d\n", size_LinkList(mylist));
	
	//销毁链表
	destroy_LinkList(mylist);
	mylist = NULL;	
}
