#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int DateType;

//ע������������ṹ��֮��Ĺ�ϵ

typedef struct QueueNode
{
	struct QueueNode* next;
	DateType data;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail;
	size_t size;
}Queue;

//��ʼ������
void QueueInit(Queue* ps);

//���ٶ���
void QueueDestroy(Queue* ps);

//���
void QueuePush(Queue* ps, DateType x);

//����
void QueuePop(Queue* ps);

//��ȡ����Ԫ��
DateType QueueFront(Queue* ps);

//��ȡ��βԪ��
DateType QueueBack(Queue* ps);

//��ȡ��ЧԪ�ظ���
size_t QueueSize(Queue* ps);

//�ж϶��Ƿ�Ϊ��
bool QueueEmpty(Queue* ps);





