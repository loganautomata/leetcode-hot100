#include "solution.h"

using namespace std;

int Solution::search(vector<int> &nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    int middle = 0;
    bool flag = true;
    if (target < nums[0])
    {
        flag = false;
    }
    while (left <= right)
    {
        middle = (left + right) / 2;
        if (flag)
        {
            if (nums[middle] > target || nums[middle] < nums[0])
                right = middle - 1;
            else if (nums[middle] < target)
                left = middle + 1;
            else
            {
                return middle;
            }
        }
        else
        {
            if (nums[middle] < target || nums[middle] > nums.back())
                left = middle + 1;
            else if (nums[middle] > target)                
                right = middle - 1;
            else
            {
                return middle;
            }
        }
    }

    return -1;
}
