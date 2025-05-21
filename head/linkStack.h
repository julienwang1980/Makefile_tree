#ifndef _LINK_STACK_H_
#define _LINK_STACK_H_


typedef void * LinkStack;


//栈的顺序存储

//初始化栈
LinkStack init_LinkStack();

//入栈
void push_LinkStack(LinkStack stack, void * data);

//出栈
void pop_LinkStack(LinkStack stack);

//返回栈顶
void * top_LinkStack(LinkStack stack);

//返回栈大小
int size_LinkStack(LinkStack stack);

//判断栈是否为空
int isEmpty_LinkStack(LinkStack stack);

//销毁
void destroy_LinkStack(LinkStack stack);

//测试栈
void test();

#endif