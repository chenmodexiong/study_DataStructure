#define  _CRT_SECURE_NO_WARNINGS 1


//������м���

//���㵥�����ͷ��� head �������ҳ�������������м��㡣
//����������м��㣬�򷵻صڶ����м��㡣


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
//    //��ָ������������ָ����һ��
//    while (fast && fast->next)
//    {
//        fast = fast->next->next;
//        slow = slow->next;
//    }
//    return slow;
//}



//�����е�����k�����

//����һ����������������е�����k����㡣


/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

 /**
  *
  * @param pListHead ListNode��
  * @param k int����
  * @return ListNode��
  */
//struct ListNode* FindKthToTail(struct ListNode* pListHead, int k)
//{
//    // write code here
//    //����Ϊ��
//    if (pListHead == NULL)
//    {
//        return NULL;
//    }
//    //kΪ0
//    if (k == 0)
//    {
//        return NULL;
//    }
//    struct ListNode* fast = pListHead;
//    struct ListNode* slow = pListHead;
//    //���ÿ�ָ����k��
//    while (k--)
//    {
//        //k����������
//        if (fast == NULL)
//        {
//            return NULL;
//        }
//        fast = fast->next;
//    }
//
//    //������ָ��Ϳ�ָ��һ����
//    while (fast)
//    {
//        fast = fast->next;
//        slow = slow->next;
//    }
//    return slow;
//}


//�ϲ�������������

//��������������ϲ�Ϊһ���µ� ���� �������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ�

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
//{
//    //�ж��Ƿ��п�����
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
//        //�ý�С��β�嵽������
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
//    //list1���ȱȽ϶�
//    if (cur2)
//    {
//        //��list2��ʣ�ಿ��β���Ӽ���
//        newtail->next = cur2;
//    }
//    //list2���ȱȽ϶�
//    if (cur1)
//    {
//        //��list1��ʣ�ಿ��β����
//        newtail->next = cur1;
//    }
//    struct ListNode* head = guard->next;
//    free(guard);
//    return head;
//}

