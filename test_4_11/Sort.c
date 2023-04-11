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
//	//// ���ѡkey
//	/*int randi = left + (rand() % (right - left));
//	Swap(&a[left], &a[randi]);*/
//
//	// ����ȡ��
//	int midi = GetMidNumi(a, left, right);
//	if (midi != left)
//		Swap(&a[midi], &a[left]);
//
//	int keyi = left;
//	while (left < right)
//	{
//		// �ұ���С
//		while (left < right && a[right] >= a[keyi])
//			--right;
//
//		// ����Ҵ�
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
//	// �ݹ�
//	QuickSort(a, begin, keyi - 1);
//	QuickSort(a, keyi + 1, end);
//}


int GetMidNumi(int* arr, int left, int right)
{
	int mid = (left + right) / 2;
	//�������м�ֵ
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

//��������(������)
//hoare����İ汾
void QuickSort(int* arr, int left, int right)
{
	if (left >= right)
		return;
	/* ��¼һ����ʼλ�� */
	int begin = left;
	int end = right;
	//����
	//int keyi = left;/*�����key,�ұ�����*/
	// 
	//���ѡkey,��������ȡ�м�ֵ,���Խ��˳��������������Ч��̫�͵�����
	//int randi = left + rand() % (right - left);
	//Swap(&arr[randi], &arr[left]);
	//int keyi = left;
	//����ȡ�м�ֵ
	int midi = GetMidNumi(arr, left, right);
	if (midi != left)
		Swap(&arr[midi], &arr[left]);
	int keyi = left;
	while (left < right)
	{
		//�ұ���С
		while (left < right && arr[right] >= arr[keyi])
			--right;
		//����Ҵ�
		while (left < right && arr[left] <= arr[keyi])
			++left;

		Swap(&arr[left], &arr[right]);
	}
	Swap(&arr[keyi], &arr[left]);
	keyi = left;
	//�ݹ�
	//[begin,keyi-1] keyi [keyi+1,end] 
	QuickSort(arr, begin, keyi - 1);
	QuickSort(arr, keyi + 1, end);
}

//�ڿӷ�
void QuickSort2(int* arr, int left, int right)
{
	if (left >= right)
		return;

	/*��¼��ʼλ��*/
	int begin = left;
	int end = right;
	int key = arr[left];/* ����key */
	int hole = left;/*����ڿ�,�ұ�����*/
	while (left < right)
	{
		//�ұ���С
		while (left < right && arr[right] >= key)
			--right;
		arr[hole] = arr[right];
		hole = right;/*�����ݷ�����в����¿�*/
		//����Ҵ�
		while (left < right && arr[left] <= key)
			++left;
		arr[hole] = arr[left];
		hole = left;
	}
	arr[hole] = key;
	//�ݹ�
	//[begin,hole-1] hole [hole+1,end]
	QuickSort2(arr, begin, hole - 1);
	QuickSort2(arr, hole + 1, end);
}

//ǰ��ָ�뷨
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
	//curȥ�ұ�arr[keyi]С��ֵ
	//prev����һ������cur�򽻻�
	while (cur <= right)
	{
		while (arr[cur] < arr[keyi] && ++prev != cur)/* prevֻ����cur����С��key��ֵʱ��++ */
			Swap(&arr[cur], &arr[prev]);
		++cur;/* cur���κ��������++ */
	}
	/*���key����prev��λ��*/
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

//�����Ż�(�Ͳ�������һ��ʹ��)
void QuickSort4(int* arr, int left, int right)
{
	if (left >= right)
		return;
	int midi = GetMidNumi(arr, left, right);
	if (midi != left)
		Swap(&arr[midi], &arr[left]);
	int keyi = midi;
	int prev = left, cur = left + 1;
	//curȥ�ұ�arr[keyi]С��ֵ,prev����һ������cur�򽻻�
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
	//curȥ�ұ�arr[keyi]С��ֵ,prev����һ������cur�򽻻�
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


//��ջʵ�ֿ��ŷǵݹ�
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



