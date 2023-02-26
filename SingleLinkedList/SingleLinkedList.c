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
	//��������Ϊ��
	if (*pphead==NULL)
	{
		*pphead = newnode;
	}
	else
	{
		//��β
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
	assert(*pphead);//����Ϊ��

	//�������
	if ((*pphead)->next==NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{	//������
		SLinkedList* cur = *pphead;
		//SLinkedList* pre = *pphead;
		//�ҡ�β��
		//while (cur->next)
		//{
		//	pre = cur;
		//	cur = cur->next;
		//}
		//free(cur);
		//cur = NULL;
		//pre->next = NULL;

		/* �ڶ���д�� */
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







