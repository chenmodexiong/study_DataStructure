#define  _CRT_SECURE_NO_WARNINGS 1

#include "DoubleLinkedList.h"

ListNode* BuyNewNode(DateType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(DateType));
	if (newnode == NULL)
	{
		perror("BuyNewNode fail\n");
		return NULL;
		//exit(-1);
	}
	newnode->date = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}


ListNode* DLLListInit()
{
	//ListNode* phead = (ListNode*)malloc(sizeof(DateType));
	//if (phead == NULL)
	//{
	//	perror("ListInit fail\n");
	//	return NULL;
	//}
	//phead->date = -1;
	//phead->next = phead;
	//phead->prev = phead;
	//return phead;

	ListNode* phead = BuyNewNode(-1);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

void DLLPushback(ListNode* phead, DateType x)
{
	ListNode* newnode = BuyNewNode(x);
	ListNode* tail = phead->prev;

	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;
}

void DLLListPrint(ListNode* phead)
{
	assert(phead);
	printf("<=head=>");
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d<=>", cur->date);
		cur = cur->next;
	}
	printf("\n");
}


















