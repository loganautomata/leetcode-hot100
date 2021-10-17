#include "solution.h"

using namespace std;

int Solution::climbStairs(int n)
{
    int pre_1 = 1;
    int pre_2 = 2;
    int res = n;

    for (int i = 3; i <= n; i++)
    {
        int temp = pre_2;
        pre_2 += pre_1;
        pre_1 = temp;
    }

    if (n > 2)
        res = pre_2;

    return res;
}
