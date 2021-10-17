#include "solution.h"

using namespace std;

vector<int> Solution::sortArray(vector<int> &nums)
{
    QuickSort(nums, make_pair(0, nums.size()));

    return nums;
}

void Solution::QuickSort(vector<int> &nums, pair<int, int> range)
{
    if (range.first + 1 == range.second)
        return; // 迭代终止条件, 区间中只有一个数时终止.

    int middle = range.first;

    // 以第一个数作为分治数, 排序后面的数组.
    for (int i = range.first + 1; i < range.second; i++)
    {
        if (nums[i] < nums[range.first])
        {
            swap(nums[middle], nums[i]);
        }
    }

    swap(nums[middle], nums[range.first]); // 将分治数放在序列中间

    QuickSort(nums, make_pair(range.first, middle + 1));
    QuickSort(nums, make_pair(middle + 1, range.second));
}
