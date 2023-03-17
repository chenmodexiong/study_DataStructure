#define  _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

int main()
{
	stack a;
	StackInit(&a);

	StackPush(&a, 1);
	StackPush(&a, 2);
	StackPush(&a, 3);
	printf("%d ", StackTop(&a));
	StackPop(&a);
	StackPush(&a, 4);
	StackPush(&a, 5);
	StackPush(&a, 6);

	while (!StackEmpty(&a))
	{
		printf("%d ",StackTop(&a));
		StackPop(&a);
	}

	return 0;
}
















