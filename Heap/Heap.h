#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define DEAULTSIZE 8

typedef int DateType;

//堆的结构
typedef struct Heap
{
	DateType* arr;//存放元素的数组
	int size;//有效元素个数
	int capacity;//容量
}Heap;

//建堆
void HeapInit(Heap* ps);

//销毁
void HeapDestroy(Heap* ps);

//堆的插入
void HeapPush(Heap* ps, DateType x);

//向上调整
void AdjustUp(DateType* ps, int child);

//堆的删除
void HeapPop(Heap* ps);

//堆的判空
int HeapEmpty(Heap* ps);

//向下调整
void AdjustDown(Heap* ps, int parent);
//void AdjustDown(DateType* a, int n, int parent);


//获取堆顶元素
DateType HeapTop(Heap* ps);

//交换
void Swap(DateType* p1, DateType* p2);


