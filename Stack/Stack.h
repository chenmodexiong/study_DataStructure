#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#define INITMAX 5

typedef int StackDateType;

//��̬��ջ
//typedef struct STStack
//{
//	StackDateType arr[N];
//	StackDateType top;//ջ��
//}Stack;


//��̬��ջ
typedef struct STStack
{
	StackDateType* arr;
	StackDateType top;//ջ��
	StackDateType capacity;//�������
}Stack;


//��ʼ��ջ
void StackInit(Stack* ps);

//��ջ
void PushStack(Stack* ps,StackDateType x);

//��ջ
void PopStack(Stack* ps);

//�ж��Ƿ�Ϊ��
bool StackEmpty(Stack* ps);

//������ЧԪ�ظ���
StackDateType StackSize(Stack* ps);

//��ȡջ��Ԫ��
StackDateType StackTop(Stack* ps);

//����ջ
void StackDestroy(Stack* ps);



