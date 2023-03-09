#define  _CRT_SECURE_NO_WARNINGS 1

#include "DoubleLinkedList.h"

int main()
{
	ListNode* plist=DLLListInit();
	DLLPushback(plist, 1);
	DLLPushback(plist, 2);
	DLLPushback(plist, 3);
	DLLPushback(plist, 4);
	DLLListPrint(plist);


	return 0;
}



















