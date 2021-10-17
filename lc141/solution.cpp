#include "solution.h"

using namespace std;

bool Solution::hasCycle(ListNode *head)
{
    bool res = false;
    ListNode *cur_1 = head, *cur_2 = head;
    if (head != nullptr)
    {
        cur_2 = cur_2->next;
    }


    for (; cur_2 != nullptr;)
    {
        if (cur_2 == cur_1)
        {
            res = true;
            break;
        }

        cur_1 = cur_1->next;
        cur_2 = cur_2->next;
        if (cur_2 != nullptr)
            cur_2 = cur_2->next;
    }

    return res;
}
