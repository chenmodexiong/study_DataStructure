#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdlib.h>
#include <stdio.h>



//�ռ临�Ӷ� O(N^2)

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
	//��һ�С��Խ��ߡ����һ������
	for (i = 0; i < 10; i++)
	{
		a[i][i] = 1;
		a[i][0] = 1;
	}
	//�����м�����
	for (i = 2; i < 10; i++)
	{
		for (j = 1; j <= i -1 ; j++)
		{
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
		}
	}
	//��ӡ����
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
//	int n = 0;                   //�����n��Ҫ̫��
//	printf("������Ҫ��ӡ������\n");//����14�л����������淶
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
//			printf("  ");//�ڴ�ӡÿ������ǰ��ӡ�ո�
//		}
//		arr[a][0] = 1;//����ߵ�1
//		for (b = 0; b <= a; b++)
//		{
//			if (a > 0 && b > 0)
//			{
//				arr[a][b] = arr[a - 1][b - 1] + arr[a - 1][b];//�м������ֵ
//			}
//			if (a == b)
//			{
//				arr[a][b] = 1;//���ұߵ�1
//			}
//			printf("%6d", arr[a][b]);
//		}
//		printf("\n");
//	}
//	return 0;
//}



