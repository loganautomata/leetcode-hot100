#include "solution.h"

using namespace std;

int Solution::trap(vector<int> &height)
{
    vector<int> dp_left(height.size(), height[0]);
    vector<int> dp_right(height.size(), height.back());
    int res = 0;

    for (int i = 1; i < height.size(); i++)
    {
        dp_left[i] = max(dp_left[i - 1], height[i]);
    }

    for (int i = height.size() - 2; i >= 0; i--)
    {
        dp_right[i] = max(dp_right[i + 1], height[i]);
    }

    for (int i = 0; i < height.size(); i++)
    {
        res += (min(dp_left[i], dp_right[i]) - height[i]);
    }

    return res;
}
