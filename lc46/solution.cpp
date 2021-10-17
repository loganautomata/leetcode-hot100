#include "solution.h"

using namespace std;

void Solution::dfs(unordered_set<int> nums, vector<int> ans)
{
    if (nums.empty())
    {
        res.push_back(ans);
        return;
    }

    for (auto &num : nums)
    {
        unordered_set<int> temp_set(nums);
        vector<int> temp_ans(ans);
        temp_set.erase(num);
        temp_ans.push_back(num);
        dfs(temp_set, temp_ans);
    }

    return;
}

vector<vector<int>> Solution::permute(vector<int> &nums)
{
    unordered_set<int> nums_set;

    for (auto &num : nums)
    {
        nums_set.insert(num);
    }

    dfs(nums_set, vector<int>());

    return res;
}
