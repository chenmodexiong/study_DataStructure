#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//void AdjustUp(int* a, int child)
//{
//	int parent = (child - 1) / 2;
//	while (child > 0)
//	{
//		if (a[child] > a[parent])/*大堆*/
//		{
//			Swap(&a[child], &a[parent]);
//			child = parent;
//			parent = (child - 1) / 2;
//		}
//		else
//			break;
//	}
//}
//
//void AdjustDown(int* a, int n, int parent)
//{
//	int child = parent * 2 + 1;/*左孩子*/
//	while (child < n)
//	{
//		//选出左右孩子中较大的
//		if (child + 1 < n && a[child + 1] > a[child])/*若要降序改此处符号*/
//			++child;
//		//向下调整
//		if (a[parent] < a[child])/*若要降序改此处符号*/
//		{
//			Swap(&a[child], &a[parent]);
//			parent = child;
//			child = parent * 2 + 1;
//		}
//		else
//			break;
//	}
//}

//排升序
//void HeapSort(int* a, int n)
//{
//	//建大堆
//	/*for (int i = 1; i < n; i++)
//	{
//		AdjustUp(a, i);
//	}*/
//
//	//建堆
//	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
//	{
//		AdjustDown(a, n, i);
//	}
//	
//	//调整
//	int end = n - 1;
//	while (end > 0)
//	{
//		Swap(&a[0], &a[end]);
//		AdjustDown(a, end, 0);
//		--end;
//	}
//
//}

void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		//大堆,选出左右孩子中较大的
		if (child + 1 < n && a[child + 1] > a[child])
			++child;
		//大堆
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}

}

//堆排序(升序)
void HeapSort(int* a, int n)
{
	//建堆
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	//调整
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}


void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}

void TestHeapSort()
{
	int a[10] = { 10,9,8,7,5,8,2,68,34,1 };
	HeapSort(a, 10);
	PrintArray(a, 10);
}

int main()
{
	TestHeapSort();
	return 0;
}













