#define  _CRT_SECURE_NO_WARNINGS 1

#include "DlinkedList.h"


int main()
{
	ListNode* plist=DLLInit();
	DLLPushBack(plist, 1);
	DLLPushBack(plist, 2);
	DLLPushBack(plist, 3);
	DLLPushBack(plist, 4);
	DLLPushBack(plist, 5);
	DLLPrint(plist);

	ListNode* pos=DLLFind(plist, 5);
	DLLErase(pos);
	DLLPrint(plist);

	//ListNode* pos = DLLFind(plist, 10);
	//DLLErase(pos);
	//DLLPrint(plist);

	//DLLPuchFront(plist,50);
	//DLLPrint(plist);
	//DLLPopBack(plist);
	//DLLPopBack(plist);
	//DLLPrint(plist);
	//DLLPopFront(plist);
	//DLLPopFront(plist);
	//DLLPopFront(plist);
	//DLLPopFront(plist);
	//DLLPopFront(plist);
	//DLLPopFront(plist);
	//DLLPrint(plist);






	return 0;
}


























