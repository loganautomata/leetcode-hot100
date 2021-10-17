#include "solution.h"

using namespace std;

int Solution::maxSubArray(vector<int> &nums)
{
    int res = INT32_MIN;

    for (int i = 0, sum = 0; i < nums.size(); i++)
    {
        if (sum < 0)
            sum = 0;

        sum += nums[i];

        if (sum > res)
            res = sum;
    }

    return res;
}
