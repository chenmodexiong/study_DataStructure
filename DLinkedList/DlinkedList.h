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

//��һ���µĽڵ�
struct DListNode* BuyNewNode(DateType x);

//��ͷ���
struct DListNode* DLLInit();

//��������Ƿ�Ϊ��
bool CheckEmpty(ListNode* head);

//˫�������ӡ
void DLLPrint(ListNode* head);

//˫������β��
void DLLPushBack(ListNode* head, DateType x);

//˫������ͷ��
void DLLPuchFront(ListNode* head, DateType x);

//˫������βɾ
void DLLPopBack(ListNode* head);

//˫������ͷɾ
void DLLPopFront(ListNode* head);

//posλ�ò���
void DLLInsert(ListNode* pos, DateType x);


























