#include "solution.h"

using namespace std;

ListNode* Solution::mergeKLists(vector<ListNode*>& lists)
{
    ListNode *head = nullptr;
    ListNode *cur = nullptr;
    priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> min_heap;

    for (auto &list : lists)
    {
        if(list != nullptr)
        {
            min_heap.push(make_pair(list->val, list));
        }
    }

    while(min_heap.size() > 1)
    {
        pair<int, ListNode*> temp = min_heap.top();
        min_heap.pop();
        if(temp.second->next != nullptr) min_heap.push(make_pair(temp.second->next->val, temp.second->next));
        if (head == nullptr)
        {
            head = temp.second;
            cur = head;
        }
        else
        {
            cur->next = temp.second;
            cur = cur->next;
        }
    }

    if (!min_heap.empty())
    {
        if (cur == nullptr)
        {
            head = min_heap.top().second;
            cur = head;
        }
        else
        {
            cur->next = min_heap.top().second;
        }
    }

    return head;
}
