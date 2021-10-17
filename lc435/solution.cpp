#include "solution.h"

using namespace std;

bool Solution::NotOverlapInterval(vector<int> interval_1, vector<int> interval_2)
{
    if (interval_1[1] <= interval_2[0] || interval_1[0] >= interval_2[1])
        return true;
    else
        return false;
}

int Solution::eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    int res = 0;
    int sum_interval = 0;

    sort(intervals.begin(), intervals.end(), [](const vector<int> &interval_1, const vector<int> &interval_2) -> const bool
         { return interval_1[1] < interval_2[1]; });

    if (!intervals.empty()) sum_interval++;
    for (int cur_in = 1, pre_in = 0; cur_in < intervals.size(); cur_in++)
    {
        if (NotOverlapInterval(intervals[pre_in], intervals[cur_in]))
        {
            sum_interval++;
            pre_in = cur_in;
        }
    }

    return intervals.size() - sum_interval;
}
