#include "solution.h"

using namespace std;

vector<vector<int>> Solution::merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> res;

    sort(intervals.begin(), intervals.end(), [](const vector<int> &interval1, const vector<int> &interval2) -> const bool
         { return interval1[0] < interval2[0]; });

    for (int i = 0; i < intervals.size();)
    {
        int start = intervals[i][0];
        int end = intervals[i][1];
        int j = i + 1;
        while (j < intervals.size() && intervals[j][0] <= end)
        {
            start = min(intervals[j][0], start);
            end = max(intervals[j][1], end);
            j++;
        }
        res.push_back(vector<int>() = {start, end});
        i = j;
    }

    return res;
}
