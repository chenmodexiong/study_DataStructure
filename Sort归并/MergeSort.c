#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void _MergeSort(int* arr, int begin, int end, int* tmp)
{
	if (begin >= end)
		return;
	int mid = (begin + end) / 2;
	//[begin,mid] [mid+1,end] 子区间递归
	_MergeSort(arr, begin, mid, tmp);
	_MergeSort(arr, mid + 1, end, tmp);
	//[begin,mid] [mid+1,end] 子区间归并
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int i = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (arr[begin1] < arr[begin2])
			tmp[i++] = arr[begin1++];
		else
			tmp[i++] = arr[begin2++];
	}
	while (begin1 <= end1)
		tmp[i++] = arr[begin1++];
	while(begin2<=end2)
		tmp[i++] = arr[begin2++];
	/*将归并后的数据拷贝回原数组*/
	memcpy(arr + begin, tmp + begin, sizeof(int) * (end - begin + 1));
}

void MergeSort(int* arr,int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail\n");
		return;
	}
	_MergeSort(arr, 0, n - 1, tmp);
	free(tmp);
}

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}


void TestMergeSort()
{
	int a[10] = { 10,8,8,76,6,5,40,4,3,2 };
	MergeSort(a, 10);
	PrintArray(a, 10);
}

int main()
{
	//TestBubbleSort();
	TestMergeSort();
	return 0;
}