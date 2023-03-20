#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int DateType;

//注意理清楚两个结构体之间的关系

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

//初始化队列
void QueueInit(Queue* ps);

//销毁队列
void QueueDestroy(Queue* ps);

//入队
void QueuePush(Queue* ps, DateType x);

//出队
void QueuePop(Queue* ps);

//获取队首元素
DateType QueueFront(Queue* ps);

//获取队尾元素
DateType QueueBack(Queue* ps);

//获取有效元素个数
size_t QueueSize(Queue* ps);

//判断队是否为空
bool QueueEmpty(Queue* ps);





