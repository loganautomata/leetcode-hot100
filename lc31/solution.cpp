#include "solution.h"

using namespace std;

void Solution::nextPermutation(vector<int> &nums)
{
    vector<pair<int, int>> arr;
    int swap_num = 0;

    for (int i = nums.size() - 1; i >= 0;)
    {
        if (arr.empty() || nums[i] > arr.back().first)
        {
            arr.push_back(make_pair(nums[i], i));
            i--;
        }
        else if (nums[i] == arr.back().first)
        {
            arr.back().second = i;
            i--;
        }
        else
        {
            pair<int, int> sw_pa = *upper_bound(arr.begin(), arr.end(), make_pair(nums[i], i), [](const pair<int, int> &p1, const pair<int, int> &p2) -> bool
                                                { return p1.first < p2.first; });
            swap(nums[sw_pa.second], nums[i]);
            swap_num = i + 1;
            break;
        }
    }
    sort(nums.begin() + swap_num, nums.end());

    return;
}
