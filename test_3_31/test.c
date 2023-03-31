#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void PrintArray(int* arr,int num)
{
	for (int i = 0; i < num; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//²åÈëÅÅÐò
void InsertSort(int* arr, int num)
{
	for (int i = 0; i < num-1; i++)
	{
		int end = i;
		int tmp = arr[i + 1];
		while (end >= 0)
		{
			if (tmp < arr[end])
			{
				arr[end + 1] = arr[end];
				end--;
			}
			else
			{
				break;
			}
		}
		arr[end + 1] = tmp;
		//PrintArray(arr,num);
	}
}

//Ï£¶ûÅÅÐò
void ShellSort(int* arr, int num)
{
	int gap = num;
	//´óÓÚ1Ê±Ô¤ÅÅÐò
	//==1Ê±²åÈëÅÅÐò
	while (gap > 1)
	{
		gap /= 2;
		for (int j = 0; j < gap; j++)
		{
			for (int i = j; i < num - gap; i+=gap)
			{
				int end = i;
				int tmp = arr[i + gap];
				while (end >= 0)
				{
					if (tmp < arr[end])/*Ä¬ÈÏÎªÉýÐò*/
					{
						arr[end + gap] = arr[end];
						end -= gap;
					}
					else
					{
						break;
					}
				}
				arr[end + gap] = tmp;
			}
		}
	}
}
	// 
	//int gap = num;
	//while (gap > 1)
	//{
	//	gap /= 2;
	//	for (int i = 0; i < num - gap; i++)
	//	{
	//		int end = i;
	//		int tmp = arr[i + gap];
	//		while (end >= 0)
	//		{
	//			if (tmp < arr[end])
	//			{
	//				arr[end + gap] = arr[end];
	//				end -= gap;
	//			}
	//			else
	//			{
	//				break;
	//			}
	//		}
	//		arr[end + gap] = tmp;
	//	}
	//}
//}




// ²âÊÔÅÅÐòµÄÐÔÄÜ¶Ô±È
void TestOP()
{
	srand((unsigned int)time(0));
	const int N = 10000000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);

	if ((a1 && a2 && a3 && a4 && a5 && a6) == 0)
	{
		perror("malloc fail\n");
		return;
	}

	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];

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
	//QuickSort(a5, 0, N - 1);
	int end5 = clock();

	int begin6 = clock();
	//MergeSort(a6, N);
	int end6 = clock();

	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	printf("SelectSort:%d\n", end3 - begin3);
	printf("HeapSort:%d\n", end4 - begin4);
	printf("QuickSort:%d\n", end5 - begin5);
	printf("MergeSort:%d\n", end6 - begin6);

	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
}



int main()
{
	int arr[10] = { 10,9,8,7,6,5,4,3,2,1 };
	//PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
	//InsertSort(arr, sizeof(arr) / sizeof(arr[0]));
	//ShellSort(arr, sizeof(arr) / sizeof(arr[0]));
	//PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
	TestOP();
}




