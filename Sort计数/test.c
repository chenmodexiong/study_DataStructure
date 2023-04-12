#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	CountSort(arr, sizeof(arr)/sizeof(arr[0]));
	PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
}


int main()
{
	TestCountSort();
	return 0;
}
