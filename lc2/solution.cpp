#include "solution.h"

using namespace std;

ListNode *Solution::addTwoNumbers(ListNode *l1, ListNode *l2)
{
    int flag = 0;

    ListNode *cur1 = l1;
    ListNode *cur2 = l2;
    ListNode *head = nullptr;
    ListNode *cur = head;

    while (cur1 != nullptr || cur2 != nullptr)
    {
        int num1 = 0;
        int num2 = 0;
        if (cur1)
            num1 = cur1->val;
        if (cur2)
            num2 = cur2->val;
        int sum = num1 + num2 + flag;

        ListNode *node = new ListNode(sum % 10);
        if (!head)
        {
            head = node;
            cur = node;
        }
        else
        {
            cur->next = node;
            cur = cur->next;
        }

        if (cur1)
            cur1 = cur1->next;
        if (cur2)
            cur2 = cur2->next;
        if (sum / 10)
            flag = 1;
        else
            flag = 0;
    }

    if (flag)
    {
        cur->next = new ListNode(1);
    }

    return head;
}
