#define  _CRT_SECURE_NO_WARNINGS 1


#include "Sort.h"

int main()
{
	int arr[10] = { 1,4,5,36,3,42,1,77,69,50 };
	//PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
	//InsertSort(arr, sizeof(arr) / sizeof(arr[0]));
	//PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
	ShellSort(arr, sizeof(arr) / sizeof(arr[0]));
	PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
	
	return 0;
}






