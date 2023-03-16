#define  _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

void StackInit(Stack* ps)
{
	assert(ps);
	ps->arr = (StackDateType*)malloc(sizeof(StackDateType) * INITMAX);
	if (ps->arr == NULL)
	{
		perror("StackInit fail\n");
		return;
	}
	ps->capacity = INITMAX;
	ps->top = 0;//top是栈顶元素的下一个下标
}

void PushStack(Stack* ps, StackDateType x)
{
	assert(x);
	//判断容量是否需要扩容
	if (ps->capacity == (ps->top+1))
	{
		StackDateType* tmp = (StackDateType*)realloc(ps->arr, sizeof(StackDateType) * ps->capacity * 2);
		if (tmp == NULL)
		{
			perror("PushStack fail\n");
			return;
		}
		ps->arr = tmp;
		ps->capacity *= 2;
	}
	//入栈
	ps->arr[ps->top] = x;
	ps->top++;
}

void PopStack(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	
	ps->top--;
}

bool StackEmpty(Stack* ps)
{
	assert(ps);

	return ps->top == 0;
}

StackDateType StackSize(Stack* ps)
{
	assert(ps);

	return ps->top;
}

StackDateType StackTop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));

	return ps->arr[ps->top-1];
}


void StackDestroy(Stack* ps)
{
	assert(ps);

	free(ps->arr);
	ps->arr = NULL;
	ps->capacity = 0;
	ps->top = 0;
}













