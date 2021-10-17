#include "solution.h"

using namespace std;

ListNode* Solution::reverseList(ListNode* head)
{
    ListNode *pre = nullptr;

    for (ListNode *cur = head; cur != nullptr;)
    {
        ListNode *temp = cur;
        cur = cur->next;
        temp->next = pre;
        pre = temp;
    }

    return pre;
}
