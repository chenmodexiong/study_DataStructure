#define  _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"


void StackInit(stack* ps)
{
	assert(ps);
	DateType* tmp = (DateType*)malloc(sizeof(DateType)*INITNUM);
	if (tmp == NULL)
	{
		perror("StackInit fail\n");
		return;
	}
	ps->arr = tmp;
	ps->capacity = INITNUM;//默认容量
	ps->top = 0;//栈顶的下一个下标
}


void StackPush(stack* ps, DateType x)
{
	assert(ps);
	//检查容量是否需要扩容
	if (ps->capacity == ps->top)
	{
		DateType* tmp = (DateType*)realloc(ps->arr, sizeof(DateType) * ps->capacity * 2);
		if (tmp == NULL)
		{
			perror("StackPush fail\n");
			return;
		}
		ps->arr = tmp;
		ps->capacity *= 2;
	}

	ps->arr[ps->top++] = x;
}


void StackDestroy(stack* ps)
{
	assert(ps);
	free(ps->arr);
	ps->arr = NULL;
	ps->capacity = 0;
	ps->top = 0;
}

void StackPop(stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));

	ps->top--;
}

DateType StackTop(stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));

	return ps->arr[ps->top - 1];
}

size_t StackSize(stack* ps)
{
	assert(ps);

	return ps->top;
}

bool StackEmpty(stack* ps)
{
	assert(ps);

	return ps->top == 0;
}








