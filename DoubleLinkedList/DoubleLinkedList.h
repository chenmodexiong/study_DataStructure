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

//��ʼ��������һ��ͷ�ڵ�
ListNode* DLLListInit();

//��һ���½ڵ�
ListNode* BuyNewNode(DateType x);

//��ӡ
void DLLListPrint(ListNode* phead);

//β��
void DLLPushback(ListNode* phead, DateType x);
















