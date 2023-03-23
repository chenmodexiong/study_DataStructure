#define  _CRT_SECURE_NO_WARNINGS 1

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

void QueueInit(Queue* ps)
{
	assert(ps);

	ps->head = ps->tail = NULL;
	ps->size = 0;
}

void QueueDestroy(Queue* ps)
{
	assert(ps);

	QNode* cur = ps->head;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	ps->head = ps->tail = NULL;
	ps->size = 0;
}


void QueuePush(Queue* ps, DateType x)
{
	assert(ps);
	//新的节点
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("QueuePush fail\n");
		return;
	}
	newnode->data = x;
	newnode->next = NULL;
	//入队
	if (ps->head == NULL)
	{
		assert(ps->tail == NULL);
		ps->head = ps->tail = newnode;
	}
	else
	{
		ps->tail->next = newnode;
		ps->tail = ps->tail->next;
	}
	ps->size++;
}

void QueuePop(Queue* ps)
{
	assert(ps);
	assert(ps->head);
	//最后一个节点
	if (ps->head->next == NULL)
	{
		free(ps->head);
		ps->head = ps->tail = NULL;
	}
	else
	{
		QNode* newhead = ps->head->next;
		free(ps->head);
		ps->head = newhead;
	}
	ps->size--;
}

DateType QueueFront(Queue* ps)
{
	assert(ps);
	assert(!QueueEmpty(ps));
	return ps->head->data;
}

DateType QueueBack(Queue* ps)
{
	assert(ps);
	assert(!QueueEmpty(ps));
	return ps->tail->data;
}

bool QueueEmpty(Queue* ps)
{
	assert(ps);
	return ps->size == 0;
}

size_t QueueSize(Queue* ps)
{
	assert(ps);
	return ps->size;
}

typedef struct {
	Queue q1;
	Queue q2;
} MyStack;

MyStack* myStackCreate()
{
	MyStack* pst = (MyStack*)malloc(sizeof(MyStack));
	if (pst == NULL)
	{
		perror("malloc fail\n");
		return NULL;
	}
	QueueInit(&pst->q1);
	QueueInit(&pst->q2);
	return pst;
}

void myStackPush(MyStack* obj, int x)
{
	//将数据入队，全部入队到不是空的队中，保留另一个队为空
	if (!QueueEmpty(&obj->q1))
	{
		QueuePush(&obj->q1, x);
	}
	else
	{
		QueuePush(&obj->q2, x);
	}
}

int myStackPop(MyStack* obj)
{
	//假设q1是空
	Queue* empty = &obj->q1;
	Queue* nonempty = &obj->q2;
	if (!QueueEmpty(&obj->q1))
	{
		empty = &obj->q2;
		nonempty = &obj->q1;
	}
	//倒数据
	while (QueueSize(nonempty) > 1)
	{
		QueuePush(empty, QueueFront(nonempty));
		QueuePop(nonempty);
	}
	int top = QueueFront(nonempty);
	QueuePop(nonempty);
	return top;
}

int myStackTop(MyStack* obj)
{
	if (!QueueEmpty(&obj->q1))
	{
		return QueueBack(&obj->q1);
	}
	else
	{
		return QueueBack(&obj->q2);
	}
}

bool myStackEmpty(MyStack* obj)
{
	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj)
{
	free(&obj->q1);
	free(&obj->q2);
	free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/


int main()
{
	MyStack* pst = myStackCreate();

	myStackFree(pst);
	return 0;
}




