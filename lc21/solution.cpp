#include "solution.h"

using namespace std;

ListNode *Solution::mergeTwoLists(ListNode *l1, ListNode *l2)
{
    ListNode *res = nullptr;

    ListNode *cur1 = l1;
    ListNode *cur2 = l2;
    ListNode *cur = res;

    while (cur1 != nullptr && cur2 != nullptr)
    {
        if (cur1->val < cur2->val)
        {
            if (res == nullptr)
            {
                res = cur1;
                cur = res;
            }
            else
            {
                cur->next = cur1;
                cur = cur->next;
            }
            cur1 = cur1->next;
        }
        else
        {
            if (res == nullptr)
            {
                res = cur2;
                cur = res;
            }
            else
            {
                cur->next = cur2;
                cur = cur->next;
            }
            cur2 = cur2->next;
        }
    }

    if (cur1 != nullptr)
    {
        if (res == nullptr)
        {
            res = cur1;
            cur = res;
        }
        else
        {
            cur->next = cur1;
        }
    }
    if (cur2 != nullptr)
    {
        if (res == nullptr)
        {
            res = cur2;
            cur = res;
        }
        else
        {
            cur->next = cur2;
        }
    }

    return res;
}
