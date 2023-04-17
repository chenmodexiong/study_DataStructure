#include "Sort.h"

void InsertSort(int* arr, int num)
{
	for (int i = 1; i < num; i++)
	{
		int tmp = arr[i];
		int end = i - 1;
		while (end >= 0)
		{
			if (arr[end] > tmp)/*升序*/
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

//两层循环的写法
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

//一层循环的写法
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
				if (tmp < arr[end])/*升序*/
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


void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void SelectSort(int* arr, int num)
{
	int left = 0, right = num - 1;
	while (left < right)
	{
		int mini = left, maxi = left;
		for (int i = left + 1 ; i <= right; i++)
		{
			if (arr[i] < arr[mini])
				mini = i;
			if (arr[i] > arr[maxi])
				maxi = i;
		}
		Swap(&arr[mini], &arr[left]);
		if (maxi == left)
			maxi = mini;
		Swap(&arr[maxi], &arr[right]);
		left++;
		right--;
	}
}


void AdjustUp(int* arr, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (arr[parent] < arr[child])
		{
			Swap(&arr[parent], &arr[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
			break;
	}
}

//for (int i = 1; i < size; i++)
//{
//	AdjustUp(arr, i);
//}

void AdjustDown(int* arr, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		/*选出较大的孩子，注意右孩子可能不存在，导致越界*/
		if (child + 1 < size && arr[child] < arr[child + 1])
			++child;

		if (arr[child] > arr[parent])
		{
			Swap(&arr[child], &arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}

//for (int i = (size - 1 - 1) / 2; i >= 0; i--)
//{
//	AdjustDown(arr, size, i);
//}


void HeapSort(int* arr, int size)
{
	for (int i = (size - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(arr, size, i);
	}
	int end = size - 1;
	while (end > 0)
	{
		Swap(&arr[0], &arr[end]);
		AdjustDown(arr, end, 0);
		--end;
	}
}

void BubbleSort(int* a, int n)
{
	for (int j = 0; j < n-1; j++)
	{
		for (int i = 1; i < n - j; i++)
		{
			if (a[i - 1] > a[i])
				Swap(&a[i - 1], &a[i]);
		}
	}
}

int GetMidi(int* a, int left, int right)
{
	int mid = (left + right) / 2;
	if ((a[left] - a[mid]) * (a[mid] - a[right]) > 0)
		return mid;
	else if ((a[mid] - a[left]) * (a[left] - a[right]) > 0)
		return left;
	else
		return right;
}
int PartSort1(int* a, int left, int right)
{
	int midi = GetMidi(a, left, right);
	Swap(&a[midi], &a[left]);
	int keyi = left;
	int begin = left, end = right;
	while (begin < end)
	{
		//注意左边选keyi右边先走，保证最后的位置正确
		//以及要注意等于号，否则会死循环
		while(begin < end && a[end] >= a[keyi])
			end--;
		while (begin < end && a[begin] <= a[keyi])
			begin++;
		Swap(&a[begin], &a[end]);
	}
	Swap(&a[keyi], &a[end]);
	keyi = end;
	return keyi;
}

int PartSort2(int* a, int left, int right)
{
	int midi = GetMidi(a, left, right);
	Swap(&a[left], &a[midi]);
	int key = a[left];
	int hole= left;
	int begin = left, end = right;
	while (begin < end)
	{
		while (begin<end && a[end] >= key)
			end--;
		a[hole] = a[end];
		hole = end;
		while (begin < end && a[begin] <= key)
			begin++;
		a[hole] = a[begin];
		hole = begin;
	}	
	a[hole] = key;
	return hole;
}

void QuickSort(int* a, int left,int right)
{
	if (left >= right)
		return;
	//int keyi = PartSort1(a, left, right);
	int keyi = PartSort2(a, left, right);
	QuickSort(a, left, keyi - 1);
	QuickSort(a, keyi + 1, right);
}








