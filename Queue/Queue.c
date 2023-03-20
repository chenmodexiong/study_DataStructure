#define  _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"

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




