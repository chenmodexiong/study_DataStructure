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

//��ӡ
void SLLPrint(SLinkedList* phead);

//������β��
void SLLPushBack(SLinkedList** pphead, SLLDateType x);

//������ͷ��
void SLLPushFront(SLinkedList** pphead, SLLDateType x);

//������βɾ
void SLLPopBack(SLinkedList** pphead);

//������ͷɾ
void SLLPopFront(SLinkedList** pphead);

//���������(�ҵ�����λ��Ҳ�൱���޸�)
SLinkedList* SLLFind(SLinkedList* plist, SLLDateType x);

//posλ�ú����
void SLLInsertAfter(SLinkedList* pos, SLLDateType x);

//posλ�ú�ɾ��
void SLLPopAfter(SLinkedList* pos);

//����Ч�ʲ��ߵ����ַ�ʽ--���Ƽ�
//posλ��ǰ����
void SLLInsertFront(SLinkedList** pphead, SLinkedList* pos, SLLDateType x);

//posλ��ɾ��
void SLLPopCurrent(SLinkedList** pphead, SLinkedList* pos);






