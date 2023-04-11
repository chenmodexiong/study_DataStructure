#define  _CRT_SECURE_NO_WARNINGS 1

#include "Sort.h"

void PrintArray(int* arr, int num)
{
	for (int i = 0; i < num; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}


//��������(����)
void InsertSort(int* arr, int num)
{
	for (int i = 1; i < num; i++)
	{
		int end = i - 1;
		int tmp = arr[i];
		while (end >= 0)
		{
			if (tmp < arr[end])/* ��Ҫ����ֻ�Ĵ˴����� */
			{
				arr[end + 1] = arr[end];
				--end;
			}
			else
			{
				break;
			}
		}
		arr[end + 1] = tmp;
	}
}

//ϣ������
void ShellSort(int* arr, int num)
{
	int gap = num;
	while (gap > 1)
	{
		gap /= 2;
		for (int i = 0; i < num - gap; i++)
		{
			int end = i;
			int tmp = arr[i + gap];
			while (end >= 0)
			{
				if (tmp < arr[end])
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


//ϣ������
//void ShellSort(int* arr, int num)
//{
//	int gap = 3;
//	for (int j = 0; j < gap; j++)
//	{
//		//һ��Ԥ����	
//		for (int i = j; i < num-gap; i += gap)
//		{
//			int end = i;
//			int tmp = arr[i+gap];
//			while (end >= 0)
//			{
//				if (tmp < arr[end])
//				{
//					arr[end + gap] = arr[end];
//					end -= gap;
//				}
//				else
//				{
//					break;
//				}
//			}
//			arr[end + gap] = tmp;
//		}
//	}
//}







