#define  _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"

int main()
{
	Queue st;
	QueueInit(&st);
	QueuePush(&st, 1);
	QueuePush(&st, 2);
	QueuePush(&st, 3);
	QueuePush(&st, 4);
	QueuePush(&st, 5);

	while (!QueueEmpty(&st))
	{
		printf("%d <- ", QueueFront(&st));
		QueuePop(&st);
	}

	//printf("%d <- ", QueueFront(&st));
	//printf("\n%zd", QueueSize(&st));
	QueueDestroy(&st);

	return 0;
}















