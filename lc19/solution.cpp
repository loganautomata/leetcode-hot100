#include "solution.h"

using namespace std;

ListNode *Solution::removeNthFromEnd(ListNode *head, int n)
{
    ListNode *cur = head;
    ListNode *pre = head;
    ListNode *pre_pre = nullptr;

    for (int i = 0; i < n; i++, cur = cur->next)
        ;

    while (cur != nullptr)
    {
        ListNode *temp = pre;
        pre = pre->next;
        cur = cur->next;
        pre_pre = temp;
    }

    if (pre_pre == nullptr)
        head = pre->next;
    else
        pre_pre->next = pre->next;

    return head;
}
