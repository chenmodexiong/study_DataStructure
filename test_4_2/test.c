#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void SelectSort(int* arr,int num)
{
	int left = 0;
	int right = num - 1;
	while (left < right)
	{
		int mini = left;
		int maxi = right;
		for (int i = left + 1; i <= right; i++)
		{
			if (arr[i] < arr[mini])
			{
				mini = i;
			}
			if (arr[i] > arr[maxi])
			{
				maxi = i;
			}
		}
		Swap(&arr[mini], &arr[left]);
		if (maxi == left)
			maxi = mini;
		Swap(&arr[maxi], &arr[right]);
			
		left++;
		right--;
	}
}

int main()
{
	int arr[10] = {10,9,8,7,6,5,3,3,2,1};
	SelectSort(arr, 10);

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}









