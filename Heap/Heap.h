#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define DEAULTSIZE 8

typedef int DateType;

//�ѵĽṹ
typedef struct Heap
{
	DateType* arr;//���Ԫ�ص�����
	int size;//��ЧԪ�ظ���
	int capacity;//����
}Heap;

//����
void HeapInit(Heap* ps);

//����
void HeapDestroy(Heap* ps);

//�ѵĲ���
void HeapPush(Heap* ps, DateType x);

//���ϵ���
void AdjustUp(DateType* ps, int child);

//�ѵ�ɾ��
void HeapPop(Heap* ps);

//�ѵ��п�
int HeapEmpty(Heap* ps);

//���µ���
void AdjustDown(Heap* ps, int parent);
//void AdjustDown(DateType* a, int n, int parent);


//��ȡ�Ѷ�Ԫ��
DateType HeapTop(Heap* ps);

//����
void Swap(DateType* p1, DateType* p2);


