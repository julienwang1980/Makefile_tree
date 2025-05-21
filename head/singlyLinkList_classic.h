#ifndef _SINGLY_LINK_LIST_CALSSIC_H_
#define _SINGLY_LINK_LIST_CALSSIC_H_

#define DEBUG(format, ...)\
	fprintf(stderr, "[DEBUG][%s:%d][%s][%s]"format, __FUNCTION__, __LINE__, __DATE__, __TIME__, ##__VA_ARGS__);//__VA_ARGS__ === a,b
#define ERROR(format, ...)\
	fprintf(stderr, "[ERROR][%s:%d][%s][%s]"format, __FUNCTION__, __LINE__, __DATE__, __TIME__, ##__VA_ARGS__);
#define LOG(format, ...)\
	fprintf(stderr, "[LOG][%s:%d][%s][%s]"format, __FUNCTION__, __LINE__, __DATE__, __TIME__, ##__VA_ARGS__);



//void * 别名
typedef void * LinkList;



//初始化链表
LinkList init_LinkList();

//插入节点
void insert_LinkList(LinkList list, int pos, void * data);

//遍历链表
void foreach_LinkList(LinkList list, void (*myPrint)(void *));

//删除链表节点，按位置删除
void removeByPos_LinkList(LinkList list, int pos);

//删除链表节点，按值删除
void removeByValue_LinkList(LinkList list, void *data, int(*myCompare)(void *, void *));

//逆序一个链表
void reverse_LinkList(LinkList list);

//返回链表长度
int size_LinkList(LinkList list);

//清空链表
void clear_LinkList(LinkList list);

//销毁列表
void destroy_LinkList(LinkList list);


//测试链表
void test();
#endif