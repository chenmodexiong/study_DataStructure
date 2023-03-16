#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#define INITMAX 5

typedef int StackDateType;

//静态的栈
//typedef struct STStack
//{
//	StackDateType arr[N];
//	StackDateType top;//栈顶
//}Stack;


//动态的栈
typedef struct STStack
{
	StackDateType* arr;
	StackDateType top;//栈顶
	StackDateType capacity;//最大容量
}Stack;


//初始化栈
void StackInit(Stack* ps);

//入栈
void PushStack(Stack* ps,StackDateType x);

//出栈
void PopStack(Stack* ps);

//判断是否为空
bool StackEmpty(Stack* ps);

//返回有效元素个数
StackDateType StackSize(Stack* ps);

//获取栈顶元素
StackDateType StackTop(Stack* ps);

//销毁栈
void StackDestroy(Stack* ps);



