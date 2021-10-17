#include "solution.h"

using namespace std;

bool Solution::canJump(vector<int>& nums)
{
    bool res = false;
    int curpoint = 0;

    while (curpoint < nums.size() - 1 && nums[curpoint] != 0)
    {
        int max_len = 0;
        int max_point = curpoint;

        for (int i = curpoint + 1; i <= curpoint + nums[curpoint] && i < nums.size(); i++)
        {
            if (i + nums[i] > max_len)
            {
                max_len = i + nums[i];
                max_point = i;
            }
        }

        curpoint = max_point;
    }
    
    if (curpoint == nums.size() - 1) res = true;

    return res;
}
