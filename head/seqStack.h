#ifndef _SEQ_STACK_H_
#define _SEQ_STACK_H_


#define  MAX 1024


typedef void * SeqStack;


//栈的顺序存储

//初始化栈
SeqStack init_SeqStack();

//入栈
void push_Seqstack(SeqStack stack, void * data);

//出栈
void pop_Seqstack(SeqStack stack);

//返回栈顶
void * top_SeqStack(SeqStack stack);

//返回栈大小
int size_SeqStack(SeqStack stack);

//判断栈是否为空
int isEmpty_SeqStack(SeqStack stack);

//销毁
void destroy_SeqStack(SeqStack stack);

//测试栈
void seqStack_test();

#endif