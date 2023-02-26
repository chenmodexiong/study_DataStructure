#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLLDateType;

typedef struct SLinkedList
{
	SLLDateType date;//������ÿ����������
	struct SLinkedList* next;//��һ�����ĵ�ַ

}SLinkedList;

//��һ���½��
SLinkedList* BuyNewNode(SLLDateType x);

//������β��
void SLLPushBack(SLinkedList** pphead, SLLDateType x);

//��ӡ
void SLLPrint(SLinkedList* phead);

//������ͷ��
void SLLPushFront(SLinkedList** pphead, SLLDateType x);

//������βɾ
void SLLPopBack(SLinkedList** pphead);

//������ͷɾ
void SLLPopFront(SLinkedList** pphead);




