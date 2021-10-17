#include "solution.h"

using namespace std;

ListNode *Solution::getIntersectionNode(ListNode *headA, ListNode *headB)
{
    unordered_set<ListNode *> nodes;
    ListNode *res = nullptr;

    for (ListNode *i = headA, *j = headB; i != nullptr || j != nullptr;)
    {
        if (i != nullptr && !nodes.insert(i).second)
        {
            res = i;
            break;
        }
        if (j != nullptr && !nodes.insert(j).second)
        {
            res = j;
            break;
        }
        if (i != nullptr)
        {
            i = i->next;
        }
        if (j != nullptr)
        {
            j = j->next;
        }
    }

    return res;
}
