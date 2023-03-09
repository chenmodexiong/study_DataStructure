#define  _CRT_SECURE_NO_WARNINGS 1


//环形链表
//给你一个链表的头节点 head ，判断链表中是否有环。
//如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。
//为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
//注意：pos 不作为参数进行传递 。仅仅是为了标识链表的实际情况。
//如果链表中存在环 ，则返回 true 。 否则，返回 false 。
//
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//bool hasCycle(struct ListNode* head)
//{
//    struct ListNode* slow = head;
//    struct ListNode* fast = head;
//    while (fast && fast->next)
//    {
//        slow = slow->next;
//        fast = fast->next->next;
//
//        if (fast == slow)
//            return true;
//    }
//    return false;
//}




//环形链表II

//给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
//如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 
//为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
//如果 pos 是 - 1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。
//不允许修改 链表。

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* detectCycle(struct ListNode* head)
{
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while (fast && fast->next)
    {
        //找相遇点
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow)
        {
            struct ListNode* commen = fast;
            struct ListNode* start = head;
            //相遇点和起始点一起走，正好在入口处相遇
            // while(commen && start)
            // {
            //     if (commen == start)
            //     {
            //         return commen;
            //     }
            //     commen = commen->next;
            //     start = start->next;
            // }
            while (commen != start)
            {
                commen = commen->next;
                start = start->next;
            }
            return commen;
        }
    }
    return NULL;
}



#include <stdio.h>
#include <stdlib.h>

struct ListNode 
{
    int val;
    struct ListNode *next;
};

struct ListNode* detectCycle(struct ListNode* head)
{
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while (fast && fast->next)
    {
        //找相遇点
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow)
        {
            struct ListNode* commen = fast;
            struct ListNode* start = head;
            //相遇点和起始点一起走，正好在入口处相遇
            while (commen && start)
            {
                if (commen == start)
                {
                    return commen;
                }
                commen = commen->next;
                start = start->next;
            }
        }
    }
    return NULL;
}

int main()
{
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* cur = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = cur;
    cur->val = 2;
    cur->next = head;
    struct ListNode* ret = detectCycle(head);
    return 0;
}
