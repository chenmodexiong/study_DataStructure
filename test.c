#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	char a = 'p';
	char* pa = &a;
	*pa = 'b';
	printf("%c\n",a);
	return 0;
}
//int main()
//{
//	int a = 10;
//	int* pa = &a;
//	*pa = 20;
//	printf("%d\n",a);
//	return 0;
//}
//int main()
//{
//	int a = 10;
//	int* i = &a;
//	printf("%p\n",&a);
//	printf("%p\n",i);
//	return 0;
//}
//int main()
//{
//	printf("%d\n",sizeof(int*));
//	printf("%d\n", sizeof(float*));
//	printf("%d\n", sizeof(char*));
//	return 0;
//}

//int main()
//{
//	int i = 10;
//	printf("%p\n",&i);
//	return 0;
//}