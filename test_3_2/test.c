#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>


//给你一个链表的头节点 head 和一个整数 val ，
//请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
//示例 1
//输入：head = [1, 2, 6, 3, 4, 5, 6], val = 6
//输出：[1, 2, 3, 4, 5]

//*
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
 

//struct ListNode* removeElements(struct ListNode* head, int val)
//{
//    struct ListNode* fast = head;
//    struct ListNode* slow = NULL;
//    while (fast)
//    {
//        if (fast->val != val)
//        {
//            slow = fast;
//            fast = fast->next;
//        }
//        else
//        {
//            //第一个就是要删除的数字情况
//            if (slow == NULL)
//            {
//                head = fast->next;
//                free(fast);
//                fast = head;
//            }
//            else
//            {
//                slow->next = fast->next;
//                free(fast);
//                fast = slow->next;
//            }
//        }
//
//    }
//    return head;
//}

//给你单链表的头结点 head ，请你找出并返回链表的中间结点。
//
//如果有两个中间结点，则返回第二个中间结点


//struct ListNode* middleNode(struct ListNode* head)
//{
//    struct ListNode* fast = head;
//    struct ListNode* slow = head;
//
//    while (fast && fast->next)
//    {
//        slow = slow->next;
//        fast = fast->next->next;
//    }
//
//    return slow;
//}


//输入一个链表，输出该链表中倒数第k个结点。

//struct ListNode* FindKthToTail(struct ListNode* pListHead, int k)
//{
//    if (pListHead == NULL)//链表为空
//    {
//        return NULL;
//    }
//    if (k == 0)
//    {
//        return NULL;//k为0
//    }
//    struct ListNode* fast, * slow;
//    fast = slow = pListHead;
//    //fast先走k步
//    while (k--)
//    {
//        if (fast == NULL)//当k大于链表长度时
//        {
//            return NULL;
//        }
//        fast = fast->next;
//    }
//    //再一起走，当fast为NULL时slow正好在倒数第k个
//    while (fast)
//    {
//        slow = slow->next;
//        fast = fast->next;
//    }
//    return slow;
//}


//给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。

//struct ListNode* reverseList(struct ListNode* head)
//{
//    struct ListNode* newnode = NULL;
//    struct ListNode* cur = head;
//    while (cur)
//    {
//        struct ListNode* tmp = cur->next;
//        cur->next = newnode;
//        newnode = cur;
//        cur = tmp;
//    }
//    return newnode;
//}




















