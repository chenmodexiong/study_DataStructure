#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//冒泡O(N^2)
void BubbleSort(int* a, int n)
{
	for (int j = 0; j < n - 1; j++)
	{
		for (int i = 1; i < n-j; i++)
		{
			if (a[i - 1] > a[i])/*若需要降序改此处即可*/
				Swap(&a[i - 1], &a[i]);
		}
	}
}

//选择排序
void SelectSort(int* a, int n)
{
	int left = 0;
	int right = n - 1;
	while (left < right)
	{
		int mini = left;
		int maxi = left;
		for (int i = left + 1; i <= right; i++)
		{
			if (a[i] < a[mini])
				mini = i;
			if (a[i] > a[maxi])
				maxi = i;
		}
		Swap(&a[mini], &a[left]);
		if (maxi == left)/*一次选两个数的话,注意交换后要调整*/
			maxi = mini;
		Swap(&a[maxi], &a[right]);

		/*Swap(&a[maxi], &a[right]);
		if (mini == right)
			mini = maxi;
		Swap(&a[mini], &a[left]);*/
		++left;
		--right;
	}
}

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void TestBubbleSort()
{
	int a[10] = { 10,8,8,76,6,5,40,4,3,2 };
	BubbleSort(a, 10);
	PrintArray(a, 10);
}

void TestSelectSort()
{
	int a[10] = { 10,8,8,76,6,5,40,4,3,2 };
	SelectSort(a, 10);
	PrintArray(a, 10);
}

int main()
{
	//TestBubbleSort();
	TestSelectSort();
	return 0;
}











