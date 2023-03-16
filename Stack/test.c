#define  _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"


int main()
{
	Stack a;
	Stack* pc = &a;
	StackInit(pc);

	PushStack(pc, 1);
	PushStack(pc, 2);

	printf("%d ", StackTop(pc));
	PopStack(pc);
	
	PushStack(pc, 3);
	PushStack(pc, 4);
	PushStack(pc, 5);
	PushStack(pc, 6);

	while (!StackEmpty(pc))
	{
		printf("%d ", StackTop(pc));
		PopStack(pc);
	}

	StackDestroy(pc);

	return 0;
}
