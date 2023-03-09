#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DateType;

typedef struct ListNode
{
	struct ListNode* prev;
	struct ListNode* next;

	DateType date;
}ListNode;

//初始化，创建一个头节点
ListNode* DLLListInit();

//开一个新节点
ListNode* BuyNewNode(DateType x);

//打印
void DLLListPrint(ListNode* phead);

//尾插
void DLLPushback(ListNode* phead, DateType x);
















