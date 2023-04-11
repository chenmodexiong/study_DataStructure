#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#define INITNUM 5

typedef int DateType;

typedef struct Stack
{
	DateType* arr;//用数组来实现栈
	size_t top;//栈顶
	size_t capacity;//容量
}stack;


//初始化栈
void StackInit(stack* ps);

//销毁栈
void StackDestroy(stack* ps);

//入栈
void StackPush(stack* ps, DateType x);

//出栈
void StackPop(stack* ps);

//获取栈顶元素
DateType StackTop(stack* ps);

//获取栈的有效元素个数
size_t StackSize(stack* ps);

//判断栈是否为空
bool StackEmpty(stack* ps);










