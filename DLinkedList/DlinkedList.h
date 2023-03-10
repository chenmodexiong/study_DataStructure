#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int DateType;

typedef struct DListNode
{
	struct DListNode* prev;
	struct DListNode* next;
	DateType date;
}ListNode;

//开一个新的节点
struct DListNode* BuyNewNode(DateType x);

//开头结点
struct DListNode* DLLInit();

//检查链表是否为空
bool CheckEmpty(ListNode* head);

//双向链表打印
void DLLPrint(ListNode* head);

//双向链表尾插
void DLLPushBack(ListNode* head, DateType x);

//双向链表头插
void DLLPuchFront(ListNode* head, DateType x);

//双向链表尾删
void DLLPopBack(ListNode* head);

//双向链表头删
void DLLPopFront(ListNode* head);

//pos位置插入
void DLLInsert(ListNode* pos, DateType x);


























