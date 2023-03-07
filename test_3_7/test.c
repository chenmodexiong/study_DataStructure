#define  _CRT_SECURE_NO_WARNINGS 1




//链表的回文结构
//
//描述
//对于一个链表，请设计一个时间复杂度为O(n), 额外空间复杂度为O(1)的算法，判断其是否为回文结构。
//给定一个链表的头指针A，请返回一个bool值，代表其是否为回文结构。保证链表长度小于等于900。
//测试样例：
//1->2->2->1
//返回：true


//
//
///*
//struct ListNode {
//    int val;
//    struct ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};*/
//#include <cstddef>
//class PalindromeList {
//public:
//
//    struct ListNode* midnode(struct ListNode* head)
//    {
//        struct ListNode* fast = head;
//        struct ListNode* slow = head;
//        //找中间节点
//        while (fast && fast->next)
//        {
//            slow = slow->next;
//            fast = fast->next->next;
//        }
//        return slow;
//    }
//
//    struct ListNode* reverse(struct ListNode* head)
//    {
//        struct ListNode* newhead = NULL;
//        struct ListNode* cur = head;
//        struct ListNode* curnext = NULL;
//        while (cur)
//        {
//            //保存下个位置
//            curnext = cur->next;
//            //头插
//            cur->next = newhead;
//            newhead = cur;
//            cur = curnext;
//        }
//        return newhead;
//    }
//    bool chkPalindrome(ListNode* A)
//    {
//        // write code here
//        struct ListNode* mid = midnode(A);
//        struct ListNode* rehead = reverse(mid);//后半段逆置
//        struct ListNode* head = A;//头指针
//        while (rehead)
//        {
//            if (rehead->val != head->val)
//                return false;
//            head = head->next;
//            rehead = rehead->next;
//        }
//        return true;
//    }
//};

//
//给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。
//如果两个链表不存在相交节点，返回 null 。
//图示两个链表在节点 c1 开始相交：
//题目数据 保证 整个链式结构中不存在环。
//注意，函数返回结果后，链表必须 保持其原始结构 。


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//
//struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
//{
//    //遍历链表
//    struct ListNode* cur1 = headA;
//    struct ListNode* cur2 = headB;
//    int count1 = 0;
//    int count2 = 0;
//    while (cur1)
//    {
//        count1++;
//        cur1 = cur1->next;
//    }
//    while (cur2)
//    {
//        count2++;
//        cur2 = cur2->next;
//    }
//    cur1 = headA;
//    cur2 = headB;
//    if (count1 > count2)
//    {
//        //两链表的长度差值
//        int subnum = count1 - count2;
//        while (subnum--)
//        {
//            cur1 = cur1->next;
//        }
//    }
//    else
//    {
//        int subnum = count2 - count1;
//        while (subnum--)
//        {
//            cur2 = cur2->next;
//        }
//    }
//    //再让两个链表同时走并判断
//    while (cur1 && cur2)
//    {
//        if (cur1 == cur2)
//        {
//            return cur1;
//        }
//        cur1 = cur1->next;
//        cur2 = cur2->next;
//    }
//    return NULL;
//}




