#define  _CRT_SECURE_NO_WARNINGS 1


//链表的中间结点

//给你单链表的头结点 head ，请你找出并返回链表的中间结点。
//如果有两个中间结点，则返回第二个中间结点。


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//
//struct ListNode* middleNode(struct ListNode* head)
//{
//    struct ListNode* fast = head;
//    struct ListNode* slow = head;
//    //快指针走两步，慢指针走一步
//    while (fast && fast->next)
//    {
//        fast = fast->next->next;
//        slow = slow->next;
//    }
//    return slow;
//}



//链表中倒数第k个结点

//输入一个链表，输出该链表中倒数第k个结点。


/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

 /**
  *
  * @param pListHead ListNode类
  * @param k int整型
  * @return ListNode类
  */
//struct ListNode* FindKthToTail(struct ListNode* pListHead, int k)
//{
//    // write code here
//    //链表为空
//    if (pListHead == NULL)
//    {
//        return NULL;
//    }
//    //k为0
//    if (k == 0)
//    {
//        return NULL;
//    }
//    struct ListNode* fast = pListHead;
//    struct ListNode* slow = pListHead;
//    //先让快指针走k步
//    while (k--)
//    {
//        //k大于链表长度
//        if (fast == NULL)
//        {
//            return NULL;
//        }
//        fast = fast->next;
//    }
//
//    //再让慢指针和快指针一起走
//    while (fast)
//    {
//        fast = fast->next;
//        slow = slow->next;
//    }
//    return slow;
//}


//合并两个有序链表

//将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
//{
//    //判断是否有空链表
//    if (list1 == NULL)
//    {
//        return list2;
//    }
//    if (list2 == NULL)
//    {
//        return list1;
//    }
//    struct ListNode* cur1 = list1;
//    struct ListNode* cur2 = list2;
//    struct ListNode* guard = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* newtail = guard;
//    while (cur1 && cur2)
//    {
//        //让较小的尾插到新链表
//        if (cur1->val < cur2->val)
//        {
//            newtail->next = cur1;
//            newtail = newtail->next;
//            cur1 = cur1->next;
//        }
//        else
//        {
//            newtail->next = cur2;
//            newtail = newtail->next;
//            cur2 = cur2->next;
//        }
//    }
//    //list1长度比较短
//    if (cur2)
//    {
//        //将list2的剩余部分尾连接即可
//        newtail->next = cur2;
//    }
//    //list2长度比较短
//    if (cur1)
//    {
//        //将list1的剩余部分尾连接
//        newtail->next = cur1;
//    }
//    struct ListNode* head = guard->next;
//    free(guard);
//    return head;
//}

