#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void CountSort(int* arr, int n)
{
	/*�ҳ����ֵ����Сֵ*/
	int max = arr[0], min = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	}
	/*������������������*/
	int range = max - min + 1;
	int* countA = (int*)malloc(sizeof(int) * range);
	if (countA == NULL)
	{
		perror("malloc fail\n");
		return;
	}
	memset(countA, 0, sizeof(int) * range);
	/*����*/
	for (int i = 0; i < n; i++)
	{
		countA[arr[i] - min]++;
	}
	/*����*/
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
