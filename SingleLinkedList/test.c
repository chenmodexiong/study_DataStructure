#define  _CRT_SECURE_NO_WARNINGS 1

#include "SingleLinkedList.h"


void VoidTest1()
{
	SLinkedList* plist = NULL;
	SLLPushBack(&plist, 1);
	SLLPushBack(&plist, 2);
	SLLPushBack(&plist, 3);
	SLLPushBack(&plist, 4);
	SLLPrint(plist);

}

void VoidTest2()
{
	SLinkedList* plist = NULL;
	SLLPushFront(&plist, 1);
	SLLPushFront(&plist, 2);
	SLLPushFront(&plist, 3);
	SLLPushFront(&plist, 4);
	SLLPrint(plist);

}

void VoidTest3()
{
	SLinkedList* plist = NULL;
	SLLPushFront(&plist, 1);
	SLLPushFront(&plist, 2);
	SLLPushFront(&plist, 3);
	SLLPushFront(&plist, 4);
	SLLPrint(plist);

	SLLPopBack(&plist);
	SLLPopBack(&plist);
	SLLPrint(plist);

	SLLPopBack(&plist);
	SLLPopBack(&plist);
	SLLPopBack(&plist);
	//SLLPopBack(&plist);
	SLLPrint(plist);

}

void VoidTest4()
{
	SLinkedList* plist = NULL;
	SLLPushFront(&plist, 1);
	SLLPushFront(&plist, 2);
	SLLPushFront(&plist, 3);
	SLLPushFront(&plist, 4);
	SLLPrint(plist);

	SLLPopFront(&plist);
	SLLPopFront(&plist);
	SLLPrint(plist);
	SLLPopFront(&plist);
	SLLPopFront(&plist);
	SLLPopFront(&plist);
	SLLPrint(plist);

}

int main()
{
	VoidTest4();
	//VoidTest3();
	//VoidTest2();
	//VoidTest1();

	return 0;
}

//void test1(int* pc)
//{
//	pc = NULL;
//}
//
//int main()
//{
//	int a = 0;
//	test1(&a);
//	return 0;
//}







