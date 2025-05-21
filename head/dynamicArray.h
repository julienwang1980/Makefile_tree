#ifndef _DYNAMIC_ARRAY_H_
#define _DYNAMIC_ARRAY_H_

#define DEBUG(format, ...)\
	fprintf(stderr, "[DEBUG][%s:%d][%s][%s]"format, __FUNCTION__, __LINE__, __DATE__, __TIME__, ##__VA_ARGS__);//__VA_ARGS__ === a,b
#define ERROR(format, ...)\
	fprintf(stderr, "[ERROR][%s:%d][%s][%s]"format, __FUNCTION__, __LINE__, __DATE__, __TIME__, ##__VA_ARGS__);
#define LOG(format, ...)\
	fprintf(stderr, "[LOG][%s:%d][%s][%s]"format, __FUNCTION__, __LINE__, __DATE__, __TIME__, ##__VA_ARGS__);


//动态数据结构体
struct dynamicArray
{
	void ** pAddr; // 维护开辟到堆区真实数组的指针

	int m_Capacity; //数组容量

	int m_Size; //数组大小
};

//初始化数组 参数代表 初始化的容量
struct dynamicArray * init_dynamicArray(int capacity);

//插入元素
void insert_dynamicArray(struct dynamicArray * arr, int pos, void * data);

//遍历数组
void foreach_dynamicArray(struct dynamicArray * arr, void(*myPrint)(void *));

//删除数组
void removeByPos_dynamicArray(struct dynamicArray * arr, int pos);

//按照值 来删除数组中数据
void removeByValue_dynamicArray(struct dynamicArray * arr, void * data, int(*myCompare)(void *, void *));

//销毁数组
void destroy_dynamicArray(struct dynamicArray * arr);


//测试动态数组
void test();

#endif