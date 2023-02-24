#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define InitCapacity 5


typedef int SeqDataType;


typedef struct SeqList
{
	SeqDataType* pc;//���˳����ַ
	int size;//��Ч���ݸ���
	int capacity;//˳�������
}SeqList;


//��ʼ��
void SeqListInit(SeqList* ps);

//˳�������
void SeqListDestroy(SeqList* ps);

//��ӡ
void SeqListPrint(SeqList* ps);

//�������
void SeqListCheckCapacity(SeqList* ps);

//����β��
void SeqListPushBack(SeqList* ps, SeqDataType a);

//����βɾ
void SeqListPopBack(SeqList* ps);

//����ͷ��
void SeqListPushFront(SeqList* ps,SeqDataType a);

//����ͷɾ
void SeqListPopFront(SeqList* ps);

//��������λ�ò���
void SeqListInsert(SeqList* ps, int pos, SeqDataType a);

//��������λ��ɾ��
void SeqListErase(SeqList* ps, int pos);

//��������
int SeqListFind(SeqList* ps, SeqDataType a);

//�޸�����
void SeqListModify(SeqList* ps, int pos);









