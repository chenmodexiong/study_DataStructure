#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

//ð������
//������
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
			if (arr[i-1] > arr[i])/*���Ž���ֻ�Ĵ˴�����*/
				Swap(&arr[i-1], &arr[i]);
		}
	}
}


//ϣ������
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
void QuickSort1(int* arr, int left,int right)
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
		while (left<right && arr[right] >= arr[keyi])
			--right;
		//����Ҵ�
		while (left<right && arr[left] <= arr[keyi])
			++left;

		Swap(&arr[left], &arr[right]);
	}
	Swap(&arr[keyi], &arr[left]);
	keyi = left;
	//�ݹ�
	//[begin,keyi-1] keyi [keyi+1,end] 
	QuickSort1(arr, begin, keyi - 1);
	QuickSort1(arr, keyi+1, end);
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
		while(arr[cur] < arr[keyi] && ++prev != cur)/* prevֻ����cur����С��key��ֵʱ��++ */
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

	//// ���ѡkey
	/*int randi = left + (rand() % (right - left));
	Swap(&a[left], &a[randi]);*/

	// ����ȡ��
	int midi = GetMidNumi2(a, left, right);
	if(midi != left)
		Swap(&a[midi], &a[left]);

	int keyi = left;
	while (left < right)
	{
		// �ұ���С
		while (left < right && a[right] >= a[keyi])
			--right;

		// ����Ҵ�
		while (left < right && a[left] <= a[keyi])
			++left;

		Swap(&a[left], &a[right]);
	}

	Swap(&a[keyi], &a[left]);
	keyi = left;

	// [begin, keyi-1] keyi [keyi+1, end] 
	// �ݹ�
	QuickSort1(a, begin, keyi - 1);
	QuickSort1(a, keyi+1, end);
}

 //������������ܶԱ�
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








