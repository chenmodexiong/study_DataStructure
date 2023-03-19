#define  _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>


//#define PRINT 1
//
//int main()
//{
//#if PRINT
//	printf("you can see me!!\n");
//#endif
//	return 0;
//}


//#define PRINT 1
//
//int main()
//{
//#if PRINT
//	printf("you can see me!!\n");
//#endif
//	return 0;
//}


//#define PRINT 1
//
//int main()
//{
//#if PRINT==1
//	printf("hehe\n");
//#elif PRINT==2
//	printf("haha\n");
//#else 
//	printf("heihei\n");
//#endif
//	return 0;
//}

//#define PRINT 
//
//int main()
//{
//#if defined(PRINT)
//	printf("you can see me!!\n");
//#endif
//	return 0;
//}

//#define PRINT 0
//
//int main()
//{
//#ifdef PRINT
//	printf("you can see me!!\n");
//#endif
//	return 0;
//}


#define PRINT 0

int main()
{
#ifndef PRINT
	printf("you can see me!!\n");
#else
	printf("1111111");
#endif
	return 0;
}










