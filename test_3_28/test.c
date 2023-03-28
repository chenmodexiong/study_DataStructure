#define  _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"


int main()
{
	Heap st;
	HeapInit(&st);
	HeapPush(&st, 1);
	HeapPush(&st, 2);
	HeapPush(&st, 3);
	HeapPush(&st, 4);
	HeapPush(&st, 5);
	HeapPush(&st, 6);

	while (!HeapEmpty(&st))
	{
		printf("%d ", HeapTop(&st));
		HeapPop(&st);
	}

	//Heap hp;
	//HeapInit(&hp);
	//HeapPush(&hp, 1);
	//HeapPush(&hp, 2);
	//HeapPush(&hp, 3);
	//HeapPush(&hp, 4);
	//HeapPush(&hp, 5);
	//HeapPush(&hp, 6);
	//HeapPush(&hp, 7);
	//HeapPush(&hp, 8);
	//HeapPush(&hp, 9);
	//HeapPush(&hp, 10);
	//HeapPush(&hp, 11);
	//HeapPush(&hp, 12);
	//HeapPush(&hp, 13);
	//HeapPush(&hp, 14);
	//HeapPush(&hp, 15);

	//while (!HeapEmpty(&hp))
	//{
	//	printf("%d ", HeapTop(&hp));
	//	HeapPop(&hp);
	//}
	//printf("\n");

	return 0;
}
















