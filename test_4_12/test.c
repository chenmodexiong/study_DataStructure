#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//计数排序
void CountSort(int* arr, int n)
{
	/*找出最大值和最小值*/
	int max = arr[0], min = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	}
	/*开辟用来计数的数组*/
	int range = max - min + 1;
	int* countA = (int*)malloc(sizeof(int) * range);
	if (countA == NULL)
	{
		perror("malloc fail\n");
		return;
	}
	memset(countA, 0, sizeof(int) * range);
	/*计数*/
	for (int i = 0; i < n; i++)
	{
		countA[arr[i] - min]++;
	}
	/*排序*/
	int j = 0;
	for (int i = 0; i < range; i++)
	{
		while (countA[i]--)
			arr[j++] = i + min;
	}
	free(countA);
}


void PrintArray(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void TestCountSort()
{
	int arr[] = { 10,9,9,8,7,3,4,4,2,0 };
	PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
	CountSort(arr, sizeof(arr) / sizeof(arr[0]));
	PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
}


//归并排序
void _MergeSort(int* arr, int left, int right, int* tmp)
{
	if (left >= right)
		return;
	/*平分数组,子区间排序递归*/
	int mid = (left + right) / 2;
	//[left,mid] [mid+1,right]
	_MergeSort(arr, left, mid, tmp);
	_MergeSort(arr, mid+1, right, tmp);
	/*归并*/
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int i = left;//注意！！！！
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (arr[begin1] < arr[begin2])
			tmp[i++] = arr[begin1++];
		else
			tmp[i++] = arr[begin2++];
	}
	while (begin1 <= end1)
		tmp[i++] = arr[begin1++];
	while (begin2 <= end2)
		tmp[i++] = arr[begin2++];
	/*将tmp中数据拷贝回原数组*/
	//注意！！！！！
	memcpy(arr + left, tmp + left, sizeof(int) * (right - left + 1));
}

void MergeSort(int* arr, int n)
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

void TestMergeSort()
{
	int arr[] = { 10,9,9,8,7,3,4,4,2,0 };
	PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
	MergeSort(arr, sizeof(arr) / sizeof(arr[0]));
	PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
}

//归并(非递归)
void MergeSortNonR(int* arr, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail\n");
		return;
	}
	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;

			if (end1 >= n || begin2 >= n)
				break;
			if (end2 >= n)
				end2 = n - 1;

			int j = i;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (arr[begin1] < arr[begin2])
					tmp[j++] = arr[begin1++];
				else
					tmp[j++] = arr[begin2++];
			}
			while (begin1 <= end1)
				tmp[j++] = arr[begin1++];
			while (begin2 <= end2)
				tmp[j++] = arr[begin2++];

			memcpy(arr + i, tmp + i, sizeof(int) * (end2 - i + 1));
		}
		gap *= 2;
	}
	free(tmp);
}

void TestMergeSortNonR()
{
	int arr[] = { 10,9,9,8,7,3,4,4,2,0,50,100,-4,-3,-5 };
	PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
	MergeSortNonR(arr, sizeof(arr) / sizeof(arr[0]));
	PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
}

int main()
{
	//TestCountSort();
	//TestMergeSort();
	TestMergeSortNonR();
	return 0;
}







