#include "solution.h"

using namespace std;

ListNode *Solution::detectCycle(ListNode *head)
{
    ListNode *fast = head;
    ListNode *slow = head;

    if (head != nullptr)
    {
        fast = head->next;
        slow = head->next;
    }

    if (fast != nullptr)
    {
        fast = fast->next;
    }
    else
    {
        return fast;
    }

    while (fast != nullptr)
    {
        if (slow == fast)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            break;
        }
        slow = slow->next;
        fast = fast->next;
        if (fast != nullptr)
            fast = fast->next;
    }

    return fast;
}
