#ifndef _SEQ_QUEUE_H_
#define _SEQ_QUEUE_H_


#define  MAX 1024

typedef void * SeqQueue;

//初始化队列
SeqQueue init_SeqQueue();
//入队
void push_SeqQueue(SeqQueue queue , void * data);
//出队
void pop_SeqQueue(SeqQueue queue);
//返回队头元素
void * front_SeqQueue(SeqQueue queue);

//返回队尾元素
void * back_SeqQueue(SeqQueue queue);

//队列大小
int size_SeqQueue(SeqQueue queue);

//判断是否为空
int isEmpty_SeqQueue(SeqQueue queue);

//销毁队列
void destroy_SeqQueue(SeqQueue queue);


void seqQueue_test();
#endif