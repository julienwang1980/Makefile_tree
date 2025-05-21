#include"sort.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


//选择排序数组
void selectSort(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		//认定i为最小值下表
		int min = i;
		
		for (int j = i + 1; j < len; j++)
		{
			if (arr[min] > arr[j])
			{
				//更新真实最小值下标
				min = j;
			}
		}
		//判断认定i和min是否一样，如果不一样，交换这两个下标对应的元素
		if (i != min)
		{
			int tmp = arr[i];
			arr[i] = arr[min];
			arr[min] = tmp;
		}
	}
}

//选择排序指针数组
void selectSortPoint(char * arr[], int len)
{
	//利用选择排序 降序
	for (int i = 0; i < len; i++)
	{
		int max = i;	//i最大值下标
		for (int j = i + 1; j < len; j++)
		{
			if (strcmp(arr[max], arr[j]) < 0)
			{
				//更新最大值下标
				max = j;
			}
		}
		if (i != max)
		{
			char * tmp = arr[i];
			arr[i] = arr[max];
			arr[max] = tmp;
		}
	}
}


//插入排序数组
void insertSort(int arr[], int len)
{
	for (int i = 1; i < len; i++)
	{
		if (arr[i] < arr[i-1])
		{
			int tmp = arr[i]; //将数据保存住
			int  j = i - 1;
			for (; j >= 0 && tmp < arr[j]; j--)
			{
				//数据后移
				arr[j + 1] = arr[j];
			}

			//将j+1 的位置设置为 tmp
			arr[j + 1] = tmp;
		}
	}
}

//冒泡排序
void bubbleSort(int arr[], int len)
{
	for (int i = 0; i < len-1; i++)	//比较的轮数
	{
		//因为每次比较的次数都要减1，刚好i每次加1，所以每一轮比较的次数都是n-1
		for (int j = 0; j < len-1-i; j++)	//每一轮比较的次数
		{
			if (arr[j+1] < arr[j])
			{
				int tmp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}


void printArray(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d\n", arr[i]);
	}
}

void printArray2(char ** arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%s\n", arr[i]);
	}
}

void test()
{
	int arr1[] = { 5, 2, 1, 4, 3 };
	int len1 = sizeof(arr1) / sizeof(int);
	char* arr2[] = { "aaa", "bbb", "ccc", "ddd", "fff", "eee" };
	int len2 = sizeof(arr2) / sizeof(char*);
	int arr3[] = { 5, 2, 1, 4, 3 };
	int len3 = sizeof(arr3) / sizeof(int);
	int arr4[] = { 2, 5, 6, 3, -1 };
	int len4 = sizeof(arr3) / sizeof(int);
	
	selectSort(arr1, len1);
	selectSortPoint(arr2, len2);
	insertSort(arr3, len3);
	bubbleSort(arr4, len4);


	//打印数组
	printf("选择排序数组\n");
	printArray(arr1, len1);
	
	printf("选择排序指针数组\n");
	printArray2(arr2, len2);
	
	printf("插入排序数组\n");
	printArray(arr3, len3);
	
	printf("冒泡排序数组\n");
	printArray(arr4, len4);
}
