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

//单链表尾插
void SLLPushBack(SLinkedList** pphead, SLLDateType x);

//打印
void SLLPrint(SLinkedList* phead);

//单链表头插
void SLLPushFront(SLinkedList** pphead, SLLDateType x);

//单链表尾删
void SLLPopBack(SLinkedList** pphead);

//单链表头删
void SLLPopFront(SLinkedList** pphead);




