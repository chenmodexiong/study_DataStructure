#define  _CRT_SECURE_NO_WARNINGS 1

#include "SingleLinkedList.h"

SLinkedList* BuyNewNode(SLLDateType x)
{
	SLinkedList* newnode = (SLinkedList*)malloc(sizeof(SLinkedList));
	if (newnode == NULL)
	{
		perror("BuyNewNode::");
		return NULL;
	}
	newnode->date = x;
	newnode->next = NULL;
	return newnode;
}

void SLLPrint(SLinkedList* phead)
{
	SLinkedList* cur = phead;
	while (cur)
	{
		printf("%d -> ", cur->date);
		cur = cur->next;
	}
	printf("NULL\n");
}


void SLLPushBack(SLinkedList** pphead, SLLDateType x)
{
	SLinkedList* newnode = BuyNewNode(x);
	//本身链表为空
	if (*pphead==NULL)
	{
		*pphead = newnode;
	}
	else
	{
		//找尾
		SLinkedList* cur = *pphead;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = newnode;
	}
}

void SLLPushFront(SLinkedList** pphead,SLLDateType x)
{
	SLinkedList* newnode = BuyNewNode(x);

	newnode->next = *pphead;
	*pphead = newnode;

}

void SLLPopBack(SLinkedList** pphead)
{
	assert(*pphead);//链表为空

	//单个结点
	if ((*pphead)->next==NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{	//多个结点
		SLinkedList* cur = *pphead;
		//SLinkedList* pre = *pphead;
		//找“尾”
		//while (cur->next)
		//{
		//	pre = cur;
		//	cur = cur->next;
		//}
		//free(cur);
		//cur = NULL;
		//pre->next = NULL;

		/* 第二种写法 */
		while (cur->next->next)
		{
			cur = cur->next;
		}
		free(cur->next);
		cur->next = NULL;
	}
}

void SLLPopFront(SLinkedList** pphead)
{
	assert(*pphead);

	SLinkedList* first = *pphead;
	*pphead = (*pphead)->next;
	free(first);
	first = NULL;
}

SLinkedList* SLLFind(SLinkedList* plist, SLLDateType x)
{
	assert(plist);

	SLinkedList* cur = plist;
	while (cur)
	{
		while (cur->date != x)
		{
			cur = cur->next;
		}

		return cur;
	}
	return NULL;
}


void SLLInsertAfter(SLinkedList* pos, SLLDateType x)
{
	assert(pos);
	assert(pos->next);
	
	SLinkedList* newnode = BuyNewNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
	
}

void SLLPopAfter(SLinkedList* pos)
{
	assert(pos);
	SLinkedList* del = pos->next;
	pos->next = pos->next->next;
	free(del);
	del = NULL;
}


void SLLInsertFront(SLinkedList** pphead, SLinkedList* pos, SLLDateType x)
{
	assert(pphead);
	if (pos == *pphead)
	{
		SLLPushFront(pphead,x);
	}
	else
	{
		SLinkedList* cur = *pphead;
		while (cur->next!=pos)
		{
			cur = cur->next;
		}
		SLinkedList* newnode = BuyNewNode(x);
		newnode->next = cur->next;
		cur->next = newnode;
	}
}

void SLLPopCurrent(SLinkedList** pphead, SLinkedList* pos)
{
	assert(pphead);
	assert(pos);
	assert(*pphead);

	if (pos == *pphead)
	{
		SLLPopFront(pphead);
	}
	else
	{
		SLinkedList* cur = *pphead;
		while (cur->next != pos)
		{
			cur = cur->next;
		}
		SLinkedList* del = cur->next;
		cur->next = cur->next->next;
		free(del);
		del = NULL;
	}

}








