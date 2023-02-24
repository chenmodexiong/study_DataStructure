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
	//容量已满
	if (ps->size == ps->capacity)
	{
		//扩容两倍
		SeqDataType* tmp=(SeqDataType*)realloc(ps->pc, (ps->capacity) * sizeof(SeqDataType) * 2);
		if (tmp == NULL)
		{
			perror("SeqListCheckCapacity::");
			return;
		}
		//printf("扩容成功\n");//测试
		ps->pc = tmp;
		ps->capacity *= 2;/*注意不要忘记调整容量*/
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
		printf("error\n");//不要忘记判断有效数据size个数
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
	//ps->size++;/*不要忘记size*/
	SeqListInsert(ps, 0, a);
}


void SeqListPopFront(SeqList* ps)
{
	assert(ps);
	int begin = 0;
	if (ps->size == 0)//判断数据有效
	{
		printf("error\n");
		return;
	}
	while (begin < (ps->size - 1))
	{
		ps->pc[begin] = ps->pc[begin + 1];
		begin++;
	}

	ps->size--;/*不要忘记size*/
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


















