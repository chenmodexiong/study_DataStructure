#include "Sort.h"

void InsertSort(int* arr, int num)
{
	for (int i = 1; i < num; i++)
	{
		int tmp = arr[i];
		int end = i - 1;
		while (end >= 0)
		{
			if (arr[end] > tmp)/*����*/
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

//����ѭ����д��
//void ShellSort(int* arr, int num)
//{
//	int gap = num;
//	while (gap > 1)
//	{
//		gap /= 2;
//		for (int j = 0; j < gap; j++)
//		{
//			for (int i = j; i < num - gap; i += gap)
//			{
//				int end = i;
//				int tmp = arr[i + gap];
//				while (end >= 0)
//				{
//					if (tmp < arr[end])
//					{
//						arr[end + gap] = arr[end];
//						end -= gap;
//					}
//					else
//						break;
//				}
//				arr[end + gap] = tmp;
//			}
//		}
//	}
//}

//һ��ѭ����д��
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
					break;
			}
			arr[end + gap] = tmp;
		}
	}
}
