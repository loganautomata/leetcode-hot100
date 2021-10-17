#include "solution.h"

using namespace std;

vector<int> Solution::twoSum(vector<int>& nums, int target)
{
    vector<int> res(2, 0);
    unordered_map<int, int> nums_map;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums_map.find(target - nums[i]) != nums_map.end())
        {
            res[0] = i;
            res[1] = nums_map[target - nums[i]];
            break;
        }
        nums_map.emplace(nums[i], i);
    }

    return res;
}
