#include "solution.h"

using namespace std;

vector<vector<int>> Solution::threeSum(vector<int> &nums)
{
    vector<vector<int>> res;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() && nums[i] <= 0;)
    {
        for (int j = i + 1, k = nums.size() - 1; j < k;)
        {
            if (nums[i] + nums[j] + nums[k] == 0)
            {
                res.push_back(vector<int>() = {nums[i], nums[j], nums[k]});
                while (++j < k && nums[j] == nums[j - 1])
                    ;
                while (j < --k && nums[k] == nums[k + 1])
                    ;
            }
            else if (nums[i] + nums[j] + nums[k] < 0)
            {
                while (++j < k && nums[j] == nums[j - 1])
                    ;
            }
            else
            {
                while (j < --k && nums[k] == nums[k + 1])
                    ;
            }
        }

        while (++i < nums.size() && nums[i] == nums[i - 1])
            ;
    }

    return res;
}
