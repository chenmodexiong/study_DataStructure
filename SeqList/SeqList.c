#define  _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"


void SeqListInit(SeqList* ps)
{
	assert(ps);
	ps->pc = (SeqDataType*)malloc(InitCapacity * sizeof(SeqDataType));
	if (ps->pc == NULL)
	{
		perror("SeqListInit::");
		return;
	}
	ps->size = 0;
	ps->capacity = InitCapacity;
}

void SeqListDestroy(SeqList* ps)
{
	assert(ps);
	ps->size = 0;
	ps->capacity = 0;
	free(ps->pc);
	ps->pc = NULL;
}


void SeqListCheckCapacity(SeqList* ps)
{
	assert(ps);
	//��������
	if (ps->size == ps->capacity)
	{
		//��������
		SeqDataType* tmp=(SeqDataType*)realloc(ps->pc, (ps->capacity) * sizeof(SeqDataType) * 2);
		if (tmp == NULL)
		{
			perror("SeqListCheckCapacity::");
			return;
		}
		//printf("���ݳɹ�\n");//����
		ps->pc = tmp;
		ps->capacity *= 2;/*ע�ⲻҪ���ǵ�������*/
	}
}

void SeqListPrint(SeqList* ps)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->pc[i]);
	}

}


void SeqListPushBack(SeqList* ps, SeqDataType a)
{
	assert(ps);
	
	//SeqListCheckCapacity(ps);

	////ps->pc[ps->size] = a;
	////ps->size++;
	//ps->pc[ps->size++] = a;
	SeqListInsert(ps, ps->size, a);
}

void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	if (ps->size != 0)
	{
		ps->pc[ps->size - 1] = 0;
		ps->size--;
	}
	else
	{
		printf("error\n");//��Ҫ�����ж���Ч����size����
	}

}

void SeqListPushFront(SeqList* ps,SeqDataType a)
{
	assert(ps);
	//SeqListCheckCapacity(ps);
	//int end = ps->size - 1;
	//while (end >= 0)
	//{
	//	ps->pc[end + 1] = ps->pc[end];
	//	end--;
	//}
	//ps->pc[0] = a;
	//ps->size++;/*��Ҫ����size*/
	SeqListInsert(ps, 0, a);
}


void SeqListPopFront(SeqList* ps)
{
	assert(ps);
	int begin = 0;
	if (ps->size == 0)//�ж�������Ч
	{
		printf("error\n");
		return;
	}
	while (begin < (ps->size - 1))
	{
		ps->pc[begin] = ps->pc[begin + 1];
		begin++;
	}

	ps->size--;/*��Ҫ����size*/
}

void SeqListInsert(SeqList* ps, int pos, SeqDataType a)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	SeqListCheckCapacity(ps);
	int end = ps->size - 1;
	while (end >= pos)
	{
		ps->pc[end + 1] = ps->pc[end];
		end--;
	}
	ps->pc[pos] = a;
	ps->size++;
}


void SeqListErase(SeqList* ps, int pos)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);
	int end = ps->size - 1;
	while (end >= pos)
	{
		ps->pc[pos] = ps->pc[pos+1];
		pos++;
	}
	ps->size--;
}


int SeqListFind(SeqList* ps, SeqDataType a)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->pc[i] == a)
		{
			return i;
		}
	}
	return -1;
}

void SeqListModify(SeqList* ps, int pos)
{
	assert(ps);
	assert(pos < ps->size);
	SeqDataType mod = 0;
	printf("Enter Modify Date:>");
	scanf("%d", &mod);
	ps->pc[pos] = mod;

}


















