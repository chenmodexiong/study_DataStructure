#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

//冒泡排序
//排升序
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void BubbleSort(int* arr,int num)
{
	for (int j = 0; j < num-1; j++)
	{
		for (int i = 1; i < num-j; i++)
		{
			if (arr[i-1] > arr[i])/*若排降序只改此处即可*/
				Swap(&arr[i-1], &arr[i]);
		}
	}
}


//希尔排序
void ShellSort(int* arr,int num)
{
	int gap = num;
	while (gap > 1)
	{
		gap /= 2;
		for (int i = 0; i < num - gap; i++)
		{
			int end = i;
			int tmp = i + gap;
			while (end >= 0)
			{
				if (arr[end] > tmp)
				{
					arr[end + gap] = arr[end];
					end-=gap;
				}
				else
					break;
			}
			arr[end + gap] = tmp;
		}
	}
}


int GetMidNumi(int* arr, int left, int right)
{
	int mid = (left + right) / 2;
	//三数求中间值
	if ((arr[left] - arr[mid]) * (arr[mid] - arr[right]) > 0)
		return mid;
	else if ((arr[mid] - arr[left]) * (arr[left] - arr[right]) > 0)
		return left;
	else
		return right;

	//if (arr[left] < arr[mid])
	//{
	//	if (arr[left] > arr[right])
	//		return left;
	//	else if (arr[mid] < arr[right])
	//		return mid;
	//	else
	//		return right;
	//}
	//else /*arr[left] > arr[mid]*/
	//{
	//	if (arr[mid] > arr[right])
	//		return mid;
	//	else if (arr[left] < arr[right])
	//		return left;
	//	else
	//		return right;
	//}
		
}

//快速排序(排升序)
//hoare最初的版本
void QuickSort1(int* arr, int left,int right)
{
	if (left >= right)
		return;
	/* 记录一下起始位置 */
	int begin = left;
	int end = right;
	//单趟
	//int keyi = left;/*左边做key,右边先走*/
	// 
	//随机选key,或者三数取中间值,可以解决顺序或者逆序情况下效率太低的问题
	//int randi = left + rand() % (right - left);
	//Swap(&arr[randi], &arr[left]);
	//int keyi = left;
	//三数取中间值
	int midi = GetMidNumi(arr, left, right);
	if (midi != left)
		Swap(&arr[midi], &arr[left]);
	int keyi = left;
	while (left < right)
	{
		//右边找小
		while (left<right && arr[right] >= arr[keyi])
			--right;
		//左边找大
		while (left<right && arr[left] <= arr[keyi])
			++left;

		Swap(&arr[left], &arr[right]);
	}
	Swap(&arr[keyi], &arr[left]);
	keyi = left;
	//递归
	//[begin,keyi-1] keyi [keyi+1,end] 
	QuickSort1(arr, begin, keyi - 1);
	QuickSort1(arr, keyi+1, end);
}

//挖坑法
void QuickSort2(int* arr, int left, int right)
{
	if (left >= right)
		return;

	/*记录起始位置*/
	int begin = left;
	int end = right;
	int key = arr[left];/* 保存key */
	int hole = left;/*左边挖坑,右边先走*/
	while (left < right)
	{
		//右边找小
		while (left < right && arr[right] >= key)
			--right;
		arr[hole] = arr[right];
		hole = right;/*将数据放入坑中并更新坑*/
		//左边找大
		while (left < right && arr[left] <= key)
			++left;
		arr[hole] = arr[left];
		hole = left;
	}
	arr[hole] = key;
	//递归
	//[begin,hole-1] hole [hole+1,end]
	QuickSort2(arr, begin, hole - 1);
	QuickSort2(arr, hole + 1, end);
}

//前后指针法
void QuickSort3(int* arr, int left, int right)
{
	if (left >= right)
		return;

	int midi = GetMidNumi(arr, left, right);
	if (midi != left)
		Swap(&arr[midi], &arr[left]);
	int keyi = left;
	
	int prev = left;
	int cur = left + 1;
	//cur去找比arr[keyi]小的值
	//prev的下一个不是cur则交换
	while (cur <= right)
	{
		while(arr[cur] < arr[keyi] && ++prev != cur)/* prev只有在cur发现小于key的值时才++ */
			Swap(&arr[cur], &arr[prev]);
		++cur;/* cur在任何情况都得++ */
	}
	/*最后将key换到prev的位置*/
	Swap(&arr[prev], &arr[keyi]);
	keyi = prev;
	//[left,keyi-1] keyi [keyi+1,right]
	QuickSort3(arr, left, keyi - 1);
	QuickSort3(arr, keyi + 1, right);
}



void PrintArray(int* arr, int num)
{
	for (int i = 0; i < num; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int GetMidNumi2(int* a, int left, int right)
{
	int mid = (left + right) / 2;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[left] > a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else // a[left] > a[mid]
	{
		if (a[mid] > a[right])
		{
			return mid;
		}
		else if (a[left] < a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}

// Hoare
void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;

	int begin = left, end = right;

	//// 随机选key
	/*int randi = left + (rand() % (right - left));
	Swap(&a[left], &a[randi]);*/

	// 三数取中
	int midi = GetMidNumi2(a, left, right);
	if(midi != left)
		Swap(&a[midi], &a[left]);

	int keyi = left;
	while (left < right)
	{
		// 右边找小
		while (left < right && a[right] >= a[keyi])
			--right;

		// 左边找大
		while (left < right && a[left] <= a[keyi])
			++left;

		Swap(&a[left], &a[right]);
	}

	Swap(&a[keyi], &a[left]);
	keyi = left;

	// [begin, keyi-1] keyi [keyi+1, end] 
	// 递归
	QuickSort1(a, begin, keyi - 1);
	QuickSort1(a, keyi+1, end);
}

 //测试排序的性能对比
void TestOP()
{
	srand(time(0));
	const int N = 10000000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);
	int* a7 = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a7[i];
	}

	int begin1 = clock();
	//InsertSort(a1, N);
	int end1 = clock();

	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();

	int begin3 = clock();
	//SelectSort(a3, N);
	int end3 = clock();

	int begin4 = clock();
	//HeapSort(a4, N);
	int end4 = clock();

	int begin5 = clock();
	QuickSort(a5, 0, N - 1);
	int end5 = clock();

	int begin6 = clock();
	//MergeSort(a6, N);
	int end6 = clock();


	int begin7 = clock();
	//BubbleSort(a7, N);
	int end7 = clock();

	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	printf("SelectSort:%d\n", end3 - begin3);
	printf("HeapSort:%d\n", end4 - begin4);
	printf("QuickSort:%d\n", end5 - begin5);
	printf("MergeSort:%d\n", end6 - begin6);
	printf("BubbleSort:%d\n", end7 - begin7);

	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
	free(a7);
}

void TestQuickSort()
{
	int arr[10] = { 18,19,48,67,6,5,4,3,2,1 };
	//QuickSort1(arr, 0, 9);
	//QuickSort2(arr, 0, 9);
	QuickSort3(arr,0,9);
	PrintArray(arr, 10);
}

int main()
{
	//int arr1[10] = { 18,19,48,67,6,5,4,3,2,1 };
	//BubbleSort(arr1, 10);
	//QuickSort1(arr1, 0, 9);
	//QuickSort2(arr1, 0, 9);
	//QuickSort3(arr1, 0, 9);
	//ShellSort(arr1, 10);
	//PrintArray(arr1, 10);
	//TestQuickSort();

	TestOP();


	return 0;
}








