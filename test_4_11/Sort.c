#define  _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

//int GetMidNumi(int* a, int left, int right)
//{
//	int mid = (left + right) / 2;
//	if (a[left] < a[mid])
//	{
//		if (a[mid] < a[right])
//		{
//			return mid;
//		}
//		else if (a[left] > a[right])
//		{
//			return left;
//		}
//		else
//		{
//			return right;
//		}
//	}
//	else // a[left] > a[mid]
//	{
//		if (a[mid] > a[right])
//		{
//			return mid;
//		}
//		else if (a[left] < a[right])
//		{
//			return left;
//		}
//		else
//		{
//			return right;
//		}
//	}
//}
//
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
//
//// Hoare
//void QuickSort(int* a, int left, int right)
//{
//	if (left >= right)
//		return;
//
//	int begin = left, end = right;
//
//	//// 随机选key
//	/*int randi = left + (rand() % (right - left));
//	Swap(&a[left], &a[randi]);*/
//
//	// 三数取中
//	int midi = GetMidNumi(a, left, right);
//	if (midi != left)
//		Swap(&a[midi], &a[left]);
//
//	int keyi = left;
//	while (left < right)
//	{
//		// 右边找小
//		while (left < right && a[right] >= a[keyi])
//			--right;
//
//		// 左边找大
//		while (left < right && a[left] <= a[keyi])
//			++left;
//
//		Swap(&a[left], &a[right]);
//	}
//
//	Swap(&a[keyi], &a[left]);
//	keyi = left;
//
//	// [begin, keyi-1] keyi [keyi+1, end] 
//	// 递归
//	QuickSort(a, begin, keyi - 1);
//	QuickSort(a, keyi + 1, end);
//}


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
void QuickSort(int* arr, int left, int right)
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
		while (left < right && arr[right] >= arr[keyi])
			--right;
		//左边找大
		while (left < right && arr[left] <= arr[keyi])
			++left;

		Swap(&arr[left], &arr[right]);
	}
	Swap(&arr[keyi], &arr[left]);
	keyi = left;
	//递归
	//[begin,keyi-1] keyi [keyi+1,end] 
	QuickSort(arr, begin, keyi - 1);
	QuickSort(arr, keyi + 1, end);
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
		while (arr[cur] < arr[keyi] && ++prev != cur)/* prev只有在cur发现小于key的值时才++ */
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


void InsertSort(int* arr, int n)
{
	for (int i = 1; i < n; i++)
	{
		int tmp = arr[i];
		int end = i - 1;
		while (end >= 0)
		{
			if (tmp < arr[end])
			{
				arr[end + 1] = arr[end];
				--end;
			}
			else
				break;
		}
		arr[end + 1] = tmp;
	}
}

//快排优化(和插入排序一起使用)
void QuickSort4(int* arr, int left, int right)
{
	if (left >= right)
		return;
	int midi = GetMidNumi(arr, left, right);
	if (midi != left)
		Swap(&arr[midi], &arr[left]);
	int keyi = midi;
	int prev = left, cur = left + 1;
	//cur去找比arr[keyi]小的值,prev的下一个不是cur则交换
	while (cur <= right)
	{
		while (arr[cur] < arr[keyi] && ++prev != cur)
			Swap(&arr[cur], &arr[prev]);
		++cur;
	}
	Swap(&arr[keyi], &arr[prev]);
	keyi = prev;
	if (right - left + 1 > 10)
	{
		QuickSort4(arr, left, keyi - 1);
		QuickSort4(arr, keyi + 1, right);
	}
	else
		InsertSort(arr + left, right - left + 1);
}

int PartSort1(int* arr, int left, int right)
{
	if (left >= right)
		return;
	int midi = GetMidNumi(arr, left, right);
	if (midi != left)
		Swap(&arr[midi], &arr[left]);
	int keyi = midi;
	int prev = left, cur = left + 1;
	//cur去找比arr[keyi]小的值,prev的下一个不是cur则交换
	while (cur <= right)
	{
		while (arr[cur] < arr[keyi] && ++prev != cur)
			Swap(&arr[cur], &arr[prev]);
		++cur;
	}
	Swap(&arr[keyi], &arr[prev]);
	keyi = prev;
	return keyi;
}


//用栈实现快排非递归
void QuickSortNoR(int* arr, int left, int right)
{
	stack st;
	StackInit(&st);
	StackPush(&st, right);
	StackPush(&st, left);

	while (!StackEmpty(&st))
	{
		int begin = StackTop(&st);
		StackPop(&st);
		int end = StackTop(&st);
		StackPop(&st);
		int keyi = PartSort1(arr, begin, end);
		//[begin keyi-1] keyi [keyi+1,end]
		if (begin < keyi + 1)
		{
			StackPush(&st, keyi - 1);
			StackPush(&st, begin);
		}
		if (keyi + 1 < end)
		{
			StackPush(&st, end);
			StackPush(&st, keyi + 1);
		}
	}
	StackDestroy(&st);
}



