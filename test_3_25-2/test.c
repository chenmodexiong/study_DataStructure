#define  _CRT_SECURE_NO_WARNINGS 1

typedef struct
{
    int* arr;//存放元素
    int front;//头
    int rear;//尾的下一个位置
    int k;//队列长度为k
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
    //队列已满
    if (myCircularQueueIsFull(obj))
        return false;
    //不满则入队
    obj->arr[obj->rear++] = value;
    obj->rear %= (obj->k + 1);//一定要注意数组越界问题
    return true;//括号优先级问题
}

bool myCircularQueueDeQueue(MyCircularQueue* obj)
{
    //队列为空
    if (myCircularQueueIsEmpty(obj))
        return false;
    //不为空则出队
    obj->front++;
    obj->front %= obj->k + 1;//防止越界
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
    //数组越界问题，rear-1当rear为0时会变成-1
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