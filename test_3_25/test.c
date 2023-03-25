#define  _CRT_SECURE_NO_WARNINGS 1

#define INITNUM 5

typedef int DateType;

typedef struct Stack
{
	DateType* arr;//��������ʵ��ջ
	size_t top;//ջ��
	size_t capacity;//����
}stack;


//��ʼ��ջ
void StackInit(stack* ps);

//����ջ
void StackDestroy(stack* ps);

//��ջ
void StackPush(stack* ps, DateType x);

//��ջ
void StackPop(stack* ps);

//��ȡջ��Ԫ��
DateType StackTop(stack* ps);

//��ȡջ����ЧԪ�ظ���
size_t StackSize(stack* ps);

//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(stack* ps);

void StackInit(stack* ps)
{
	assert(ps);
	DateType* tmp = (DateType*)malloc(sizeof(DateType) * INITNUM);
	if (tmp == NULL)
	{
		perror("StackInit fail\n");
		return;
	}
	ps->arr = tmp;
	ps->capacity = INITNUM;//Ĭ������
	ps->top = 0;//ջ������һ���±�
}

void StackPush(stack* ps, DateType x)
{
	assert(ps);
	//��������Ƿ���Ҫ����
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

typedef struct {
	stack pushst;
	stack popst;
} MyQueue;


MyQueue* myQueueCreate() {
	MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
	if (obj == NULL)
	{
		perror("malloc fail\n");
		return NULL;
	}
	StackInit(&obj->pushst);
	StackInit(&obj->popst);
	return obj;
}

void myQueuePush(MyQueue* obj, int x) {
	StackPush(&obj->pushst, x);
}

int myQueuePeek(MyQueue* obj) {
	if (StackEmpty(&obj->popst))
	{
		//������
		while (!StackEmpty(&obj->pushst))
		{
			StackPush(&obj->popst, StackTop(&obj->pushst));
			StackPop(&obj->pushst);
		}
	}
	return StackTop(&obj->popst);
}

int myQueuePop(MyQueue* obj) {
	// if(StackEmpty(&obj->popst))
	// {
	//     //������
	//     while(!StackEmpty(&obj->pushst))
	//     {
	//         StackPush(&obj->popst,StackTop(&obj->pushst));
	//         StackPop(&obj->pushst);
	//     }
	// }
	int front = myQueuePeek(obj);
	StackPop(&obj->popst);
	return front;
}

bool myQueueEmpty(MyQueue* obj) {
	return StackEmpty(&obj->pushst) && StackEmpty(&obj->popst);
}

void myQueueFree(MyQueue* obj) {
	StackDestroy(&obj->pushst);
	StackDestroy(&obj->popst);
	free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/

