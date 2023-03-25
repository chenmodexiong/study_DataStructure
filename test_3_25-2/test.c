#define  _CRT_SECURE_NO_WARNINGS 1

typedef struct
{
    int* arr;//���Ԫ��
    int front;//ͷ
    int rear;//β����һ��λ��
    int k;//���г���Ϊk
} MyCircularQueue;

MyCircularQueue* myCircularQueueCreate(int k)
{
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    if (obj == NULL)
    {
        perror("malloc fail\n");
        return NULL;
    }
    obj->arr = (int*)malloc(sizeof(int) * (k + 1));
    obj->front = 0;
    obj->rear = 0;
    obj->k = k;
    return obj;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj)
{
    return obj->front == obj->rear;
}

bool myCircularQueueIsFull(MyCircularQueue* obj)
{
    return (obj->rear + 1) % (obj->k + 1) == obj->front;
    // return obj->rear+1==obj->front?true:false;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
{
    //��������
    if (myCircularQueueIsFull(obj))
        return false;
    //���������
    obj->arr[obj->rear++] = value;
    obj->rear %= (obj->k + 1);//һ��Ҫע������Խ������
    return true;//�������ȼ�����
}

bool myCircularQueueDeQueue(MyCircularQueue* obj)
{
    //����Ϊ��
    if (myCircularQueueIsEmpty(obj))
        return false;
    //��Ϊ�������
    obj->front++;
    obj->front %= obj->k + 1;//��ֹԽ��
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj)
{
    if (myCircularQueueIsEmpty(obj))
        return -1;
    else
        return obj->arr[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj)
{
    if (myCircularQueueIsEmpty(obj))
        return -1;
    else
        return obj->arr[(obj->rear - 1 + obj->k + 1) % (obj->k + 1)];
    //����Խ�����⣬rear-1��rearΪ0ʱ����-1
}

void myCircularQueueFree(MyCircularQueue* obj)
{
    free(obj->arr);
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);

 * bool param_2 = myCircularQueueDeQueue(obj);

 * int param_3 = myCircularQueueFront(obj);

 * int param_4 = myCircularQueueRear(obj);

 * bool param_5 = myCircularQueueIsEmpty(obj);

 * bool param_6 = myCircularQueueIsFull(obj);

 * myCircularQueueFree(obj);
*/