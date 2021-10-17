#include "solution.h"

using namespace std;

int Solution::findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int> nums_heap;
    int res = 0;

    for (auto &num : nums)
    {
        nums_heap.push(num);
    }

    for (int i = 0; i < k && i < nums.size(); i++)
    {
        if (i == k - 1)
            res = nums_heap.top();
        nums_heap.pop();
    }

    return res;
}
