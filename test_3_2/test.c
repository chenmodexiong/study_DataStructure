#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>


//����һ�������ͷ�ڵ� head ��һ������ val ��
//����ɾ���������������� Node.val == val �Ľڵ㣬������ �µ�ͷ�ڵ� ��
//ʾ�� 1
//���룺head = [1, 2, 6, 3, 4, 5, 6], val = 6
//�����[1, 2, 3, 4, 5]

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
//            //��һ������Ҫɾ�����������
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

//���㵥�����ͷ��� head �������ҳ�������������м��㡣
//
//����������м��㣬�򷵻صڶ����м���


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


//����һ����������������е�����k����㡣

//struct ListNode* FindKthToTail(struct ListNode* pListHead, int k)
//{
//    if (pListHead == NULL)//����Ϊ��
//    {
//        return NULL;
//    }
//    if (k == 0)
//    {
//        return NULL;//kΪ0
//    }
//    struct ListNode* fast, * slow;
//    fast = slow = pListHead;
//    //fast����k��
//    while (k--)
//    {
//        if (fast == NULL)//��k����������ʱ
//        {
//            return NULL;
//        }
//        fast = fast->next;
//    }
//    //��һ���ߣ���fastΪNULLʱslow�����ڵ�����k��
//    while (fast)
//    {
//        slow = slow->next;
//        fast = fast->next;
//    }
//    return slow;
//}


//���㵥�����ͷ�ڵ� head �����㷴ת���������ط�ת�������

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




















