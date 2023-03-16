#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdlib.h>
#include <stdio.h>



//空间复杂度 O(N^2)

//int** fun(int n) 
//{
//    int** s = (int**)malloc(n * sizeof(int*));
//    if (s == NULL)
//    {
//        perror("malloc fail\n");
//        return -1;
//    }
//    while (n--)
//    {
//        s[n] = (int*)malloc(n * sizeof(int));
//    }
//    return s;
//}
//
//int main()
//{
//    fun(5);
//    return 0;
//}




#include<stdio.h>
int main()
{
	int a[10][10]={0}, i, j;
	//第一列、对角线、最后一列数据
	for (i = 0; i < 10; i++)
	{
		a[i][i] = 1;
		a[i][0] = 1;
	}
	//处理中间数字
	for (i = 2; i < 10; i++)
	{
		for (j = 1; j <= i -1 ; j++)
		{
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
		}
	}
	//打印数组
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("%d  ", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return 0;
}


//
//#include<stdio.h>
//#define N 14
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int arr[N][N] = { 0 };
//	int n = 0;                   //输入的n不要太大
//	printf("请输入要打印的行数\n");//大于14行会造成输出不规范
//	scanf("%d", &n);
//	for (a = 0; a < n; a++)
//	{
//		//b = 10 - a;
//		//while (b--)
//		//{
//		//	printf(" ");
//		//}
//		for (int i = 0; i <n-a; i++)
//		{
//			printf("  ");//在打印每行数据前打印空格
//		}
//		arr[a][0] = 1;//最左边的1
//		for (b = 0; b <= a; b++)
//		{
//			if (a > 0 && b > 0)
//			{
//				arr[a][b] = arr[a - 1][b - 1] + arr[a - 1][b];//中间的数赋值
//			}
//			if (a == b)
//			{
//				arr[a][b] = 1;//最右边的1
//			}
//			printf("%6d", arr[a][b]);
//		}
//		printf("\n");
//	}
//	return 0;
//}



