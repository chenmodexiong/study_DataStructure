#define  _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"


void HeapInit(Heap* ps)
{
	assert(ps);

	ps->arr = (DateType*)malloc(sizeof(DateType) * DEAULTSIZE);
	if (ps->arr == NULL)
	{
		perror("malloc fail\n");
		return;
	}
	
	//ps->arr = tmp;
	ps->size = 0;
	ps->capacity = DEAULTSIZE;
}

void HeapDestroy(Heap* ps)
{
	assert(ps);

	ps->capacity = 0;
	ps->size = 0;
	free(ps->arr);
	ps->arr=NULL;
}

void Swap(DateType* p1, DateType* p2)
{
	DateType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}


//���
void AdjustUp(DateType* arr,int child)
{
	int parent = (child - 1) / 2;
	//while(parent>=0)
	while (child > 0)
	{
		if (arr[child] > arr[parent])
		{
			Swap(&arr[child], &arr[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}


void HeapPush(Heap* ps, DateType x)
{
	assert(ps);
	//����Ƿ���Ҫ����
	if (ps->size == ps->capacity)
	{
		DateType* tmp = (DateType*)realloc(ps->arr, sizeof(DateType) * ps->capacity * 2);
		if (tmp == NULL)
		{
			perror("realloc fail\n");
			return;
		}
		ps->arr = tmp;
		ps->capacity *= 2;
	}

	ps->arr[ps->size] = x;
	ps->size++;
	AdjustUp(ps->arr, ps->size - 1);
}


int HeapEmpty(Heap* ps)
{
	assert(ps);
	return ps->size == 0;
}

//���
void AdjustDown(Heap* ps, int parent)
{
	
	int child = parent * 2 + 1;
	while (child < (ps->size))
	{
		//ѡ�ϴ�ĺ���
		if ((child + 1 < ps->size) && (ps->arr[child+1] > ps->arr[child]))
		{
			++child;
		}

		if (ps->arr[parent] < ps->arr[child])
		{
			Swap(&(ps->arr[child]),&(ps->arr[parent]));
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}



void HeapPop(Heap* ps)
{
	assert(ps);
	assert(!HeapEmpty(ps));

	//ɾ��ͷ������
	//�������һ�����ݽ����������µ���
	Swap(&ps->arr[0], &ps->arr[ps->size-1]);
	--ps->size;
	
	//AdjustDown(ps->arr, ps->size ,0);
	AdjustDown(ps, 0);
}


DateType HeapTop(Heap* ps)
{
	assert(ps);
	return ps->arr[0];
}









