#ifndef _LINK_QUEUE_H_
#define _LINK_QUEUE_H_


typedef void * LinkQueue;

//初始化队列
LinkQueue init_LinkQueue();
//入队
void push_LinkQueue(LinkQueue queue, void * data);
//出队
void pop_LinkQueue(LinkQueue queue);
//返回队头
void * front_LinkQueue(LinkQueue queue);
//返回队尾
void * back_LinkQueue(LinkQueue queue);
//返回队列大小
int size_LinkQueue(LinkQueue queue);
//判断队列是否为空
int isEmpty_LinkQueue(LinkQueue queue);
//销毁队列
void destroy_LinkQueue(LinkQueue queue);

#endif
