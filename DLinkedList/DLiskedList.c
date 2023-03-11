#define  _CRT_SECURE_NO_WARNINGS 1

#include "DlinkedList.h"

struct DListNode* BuyNewNode(DateType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	if (newnode == NULL)
	{
		perror("BuyNewNode fail\n");
		//return NULL;
		exit(-1);
	}
	newnode->date = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}

struct DListNode* DLLInit()
{
	ListNode* phead = BuyNewNode(-1);
	
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

void DLLPushBack(ListNode* head,DateType x)
{
	//ListNode* newnode = BuyNewNode(x);
	//ListNode* tail = head->prev;
	//// head      tail  newnode
	//tail->next = newnode;
	//newnode->prev = tail;
	//newnode->next = head;
	//head->prev = newnode;

	DLLInsert(head,x);

}

void DLLPrint(ListNode* head)
{
	assert(head);
	printf("<=head=>");
	ListNode* cur = head->next;
	while (cur != head)
	{
		printf("%d<=>", cur->date);
		cur = cur->next;
	}
	printf("\n");

}

void DLLPuchFront(ListNode* head, DateType x)
{
	//ListNode* newnode = BuyNewNode(x);
	//ListNode* cur = head->next;

	//cur->prev = newnode;
	//newnode->next = cur;
	//newnode->prev = head;
	//head->next = newnode;

	DLLInsert(head->next, x);
}

void DLLPopBack(ListNode* head)
{
	assert(head);
	assert(!CheckEmpty(head));

	ListNode* tail = head->prev;
	ListNode* newtail = tail->prev;

	newtail->next = head;
	head->prev = newtail;

	free(tail);
	tail = NULL;
}

bool CheckEmpty(ListNode* head)
{
	assert(head);

	/*if (head->next == head)
		return true;
	else
		return false;*/

	return head->next == head;
}

void DLLPopFront(ListNode* head)
{
	assert(head);
	//ÅÐ¶ÏÁ´±íÊÇ·ñÎª¿Õ
	assert(!CheckEmpty(head));
	ListNode* first = head->next;
	ListNode* sec = first->next;

	head->next = sec;
	sec->prev = head;

	free(first);
	first = NULL;
}


void DLLInsert(ListNode* pos, DateType x)
{
	assert(pos);

	ListNode* newnode = BuyNewNode(x);
	ListNode* prev = pos->prev;
	
	prev->next = newnode;
	newnode->next = pos;
	newnode->prev = prev;
	pos->prev = newnode;

}

void DLLErase(ListNode* pos)
{
	assert(pos);

	ListNode* prev = pos->prev;
	ListNode* next = pos->next;
	prev->next = next;
	next->prev = prev;

	free(pos);
	pos = NULL;
}


ListNode* DLLFind(ListNode* head, DateType x)
{
	assert(head);
	ListNode* cur = head->next;
	while (cur != head)
	{
		if (cur->date == x)
			return cur;
		cur = cur->next;
	}
	return NULL;
}

void DLLDestroy(ListNode* head)
{
	assert(head);
	ListNode* cur = head->next;
	while (cur != head)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}

	free(head);
}


















