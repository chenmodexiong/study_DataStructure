#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#define INITNUM 5

typedef int DateType;

typedef struct Stack
{
	DateType* arr;//��������ʵ��ջ
	size_t top;//ջ��
	size_t capacity;//����
}stack;


//��ʼ��ջ
void StackInit(stack* ps);

//����ջ
void StackDestroy(stack* ps);

//��ջ
void StackPush(stack* ps, DateType x);

//��ջ
void StackPop(stack* ps);

//��ȡջ��Ԫ��
DateType StackTop(stack* ps);

//��ȡջ����ЧԪ�ظ���
size_t StackSize(stack* ps);

//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(stack* ps);










