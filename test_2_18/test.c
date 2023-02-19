#define  _CRT_SECURE_NO_WARNINGS 1


//集合 s 包含从 1 到 n 的整数。不幸的是，因为数据错误，
//导致集合里面某一个数字复制了成了集合里面的另外一个数字的值，
//导致集合丢失了一个数字并且有一个数字重复 。
//
//给定一个数组 nums 代表了集合 S 发生错误后的结果。
//请你找出重复出现的整数，再找到丢失的整数，将它们以数组的形式返回。
//示例 1：
//输入：nums = [1, 2, 2, 4]
//输出：[2, 3]
//示例 2：
//输入：nums = [1, 1]
//输出：[1, 2]

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//int* findErrorNums(int* nums, int numsSize, int* returnSize)
//{
//    *returnSize = 2;
//    int* new_nums = (int*)calloc(numsSize + 1, sizeof(int));
//    int i = 0;
//    int repeatNum = 0;
//    int lostNum = 0;
//
//    //找到重复的数字
//    for (i = 0; i < numsSize; i++)
//    {
//        if (new_nums[nums[i]] == 1)
//        {
//            repeatNum = nums[i];
//            break;
//        }
//        new_nums[nums[i]] = 1;//将对应位置数据置为1，用于判断
//    }
//    int normalSum = 0;
//    int unNormalSum = 0;
//    for (i = 0; i < numsSize; i++)
//    {
//        normalSum += i + 1;//计算正常数据的和
//        unNormalSum += nums[i];//计算重复数组数据的和
//    }
//    //原始总和，减去去掉重复后的当前总和就是丢失的数字
//    lostNum = normalSum - (unNormalSum - repeatNum);
//
//    free(new_nums);
//    int* returnNum = (int*)malloc((*returnSize) * sizeof(int));
//    returnNum[0] = repeatNum;
//    returnNum[1] = lostNum;
//    return returnNum;
//}

//
//#include <stdio.h>
//#include<string.h>
//
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    while (n)
//    {
//        int flag1 = 0;
//        int flag2 = 0;
//        int flag3 = 0;
//        char password[101] = { 0 };
//        gets(password);
//        //密码不能以数字开头
//        if (password[0] > '0' && password[0] < '9')
//        {
//            printf("NO\n");
//            continue;
//        }
//        //密码长度不小于8
//        if (strlen(password) < 8)
//        {
//            printf("NO\n");
//            continue;
//        }
//        //
//        for (int i = 0; i < strlen(password); i++)
//        {
//            if (password[i] >= 'A' && password[i] <= 'Z')
//            {
//                flag1 = 1;
//            }
//            else if (password[i] >= 'a' && password[i] <= 'z')
//            {
//                flag2 = 1;
//            }
//            else if (password[i] >= '0' && password[i] <= '9')
//            {
//                flag3 = 1;
//            }
//            else
//            {
//                printf("NO\n");
//                continue;
//            }
//        }
//        //
//        if (flag1 + flag2 + flag3 < 2)
//        {
//            printf("NO\n");
//        }
//        else
//        {
//            printf("YES\n");
//        }
//        n--;
//    }
//    return 0;
//}
//


//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//    int n = 0;
//    char password[101] = { 0 };
//    scanf("%d", &n);
//    int i = 0;
//    int j = 0;
//    for (i = 0; i < n; i++)
//    {
//        int flag1 = 0;
//        int flag2 = 0;
//        int flag3 = 0;
//        char ch = 0;
//        //scanf("%s", password);
//        gets(password);
//        if (password[0] >= '0' && password[0] <= '9' || strlen(password) < 8)
//        {
//            printf("NO\n");
//            continue;
//        }
//        for (j = 0; j < strlen(password); j++)
//        {
//            if (password[j] >= 'A' && password[j] <= 'Z')
//            {
//                flag1 = 1;
//            }
//            else if (password[j] >= 'a' && password[j] <= 'z')
//            {
//                flag2 = 1;
//            }
//            else if (password[j] >= '0' && password[j] <= '9')
//            {
//                flag3 = 1;
//            }
//            else
//            {
//                printf("NO\n");
//                continue;
//            }
//        }
//        if (flag1 + flag2 + flag3 < 2)
//        {
//            printf("NO\n");
//        }
//        else
//        {
//            printf("YES\n");
//        }
//    }
//
//    return 0;
//}
#include <stdbool.h>
#include <stdio.h>
#include <windows.h>
//
//int main()
//{
//	char a[1000];
//	int i;
//	for (i = 0; i < 1000; i++)
//	{
//		a[i] = -1 - i;
//	}
//	printf("%d\n", strlen(a)); //strlen介绍，字符串认识，\0的认识
//	printf("%d", a[255]);
//	return 0;
//}
#define EPS 0.00000000001
#include <math.h>
#include <float.h>
int main()
{
	float a = 3.14f;
	/*第一种写法*/
	if (fabs(a - 3.1) > EPS)
	{
		printf("you can see me!\n");
	}
	/*第二种写法*/
	if ((a - 3.1) > DBL_EPSILON)
	{
		printf("you can see me!\n");
	}
	return 0;
}





