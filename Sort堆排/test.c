#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

void Swap(DataType* p1, DataType* p2)
{
	DataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//���ϵ���(���)
void AdjustUp(DataType* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
			break;
	}
}

//���µ���
void AdjustDown(DataType* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		//ѡ�����Һ����д��
		if (child + 1 < n && a[child] < a[child+1])
			++child;

		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}

//�����򣬽����
//�Ž��򣬽�С��
void HeapSort(int* a, int n)
{
	//����
	/*for (int i = 1; i < n; i++)
	{
		AdjustUp(a, i);
	}*/
	//����
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}

	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}

// �����������Ǵ��/С��
//void AdjustDown(int* a, int n, int parent)
//{
//	int child = parent * 2 + 1;
//	while (child < n)
//	{
//		// ѡ�����Һ����д����һ��
//		if (child + 1 < n && a[child + 1] > a[child])
//		{
//			++child;
//		}
//
//		if (a[child] > a[parent])
//		{
//			Swap(&a[child], &a[parent]);
//			parent = child;
//			child = parent * 2 + 1;
//		}
//		else
//		{
//			break;
//		}
//	}
//}
//
//void HeapSort(int* a, int n)
//{
//	// ���� -- ���µ������� -- O(N)
//	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
//	{
//		AdjustDown(a, n, i);
//	}
//
//	// �Լ���ʵ�� -- O(N*logN)
//	int end = n - 1;
//	while (end > 0)
//	{
//		Swap(&a[end], &a[0]);
//		AdjustDown(a, end, 0);
//
//		--end;
//	}
//}


void PrintArray(int* arr,int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr[10] = { 10,9,8,7,6,5,4,3,2,1 };
	HeapSort(arr, 10);
	PrintArray(arr,10);
	return 0;
}






