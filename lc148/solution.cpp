#include "solution.h"

using namespace std;

ListNode *Solution::CutList(ListNode *head)
{
    ListNode *res = nullptr;
    int list_length = 0;
    ListNode *cur = head;

    for (; cur != nullptr; cur = cur->next)
    {
        list_length++;
    }

    cur = head;
    for (int i = 0; i < list_length / 2; i++, cur = cur->next)
    {
        if (i == list_length / 2 - 1)
        {
            res = cur->next;
            cur->next = nullptr;
        }
    }

    return res;
}

ListNode *Solution::MergeList(ListNode *list1, ListNode *list2)
{
    ListNode *res = nullptr;

    ListNode *cur1 = list1;
    ListNode *cur2 = list2;
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

ListNode *Solution::sortList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    ListNode *cut_node = CutList(head);
    ListNode *list1 = sortList(head);
    ListNode *list2 = sortList(cut_node);

    return MergeList(list1, list2);
}
