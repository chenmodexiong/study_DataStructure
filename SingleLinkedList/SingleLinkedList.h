#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLLDateType;

typedef struct SLinkedList
{
	SLLDateType date;//链表中每个结点的数据
	struct SLinkedList* next;//下一个结点的地址

}SLinkedList;

//开一个新结点
SLinkedList* BuyNewNode(SLLDateType x);

//打印
void SLLPrint(SLinkedList* phead);

//单链表尾插
void SLLPushBack(SLinkedList** pphead, SLLDateType x);

//单链表头插
void SLLPushFront(SLinkedList** pphead, SLLDateType x);

//单链表尾删
void SLLPopBack(SLinkedList** pphead);

//单链表头删
void SLLPopFront(SLinkedList** pphead);

//单链表查找(找到返回位置也相当于修改)
SLinkedList* SLLFind(SLinkedList* plist, SLLDateType x);

//pos位置后插入
void SLLInsertAfter(SLinkedList* pos, SLLDateType x);

//pos位置后删除
void SLLPopAfter(SLinkedList* pos);

//以下效率不高的两种方式--不推荐
//pos位置前插入
void SLLInsertFront(SLinkedList** pphead, SLinkedList* pos, SLLDateType x);

//pos位置删除
void SLLPopCurrent(SLinkedList** pphead, SLinkedList* pos);






