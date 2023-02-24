#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define InitCapacity 5


typedef int SeqDataType;


typedef struct SeqList
{
	SeqDataType* pc;//存放顺序表地址
	int size;//有效数据个数
	int capacity;//顺序表容量
}SeqList;


//初始化
void SeqListInit(SeqList* ps);

//顺序表销毁
void SeqListDestroy(SeqList* ps);

//打印
void SeqListPrint(SeqList* ps);

//检查容量
void SeqListCheckCapacity(SeqList* ps);

//数据尾插
void SeqListPushBack(SeqList* ps, SeqDataType a);

//数据尾删
void SeqListPopBack(SeqList* ps);

//数据头插
void SeqListPushFront(SeqList* ps,SeqDataType a);

//数据头删
void SeqListPopFront(SeqList* ps);

//数据任意位置插入
void SeqListInsert(SeqList* ps, int pos, SeqDataType a);

//数据任意位置删除
void SeqListErase(SeqList* ps, int pos);

//查找数据
int SeqListFind(SeqList* ps, SeqDataType a);

//修改数据
void SeqListModify(SeqList* ps, int pos);









