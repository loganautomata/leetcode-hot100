#ifndef SOLUTION_H
#define SOLUTION_H

#include <cmath>
#include <algorithm>
#include <array>
#include <vector>
#include <list>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include "TreeNode.h"
#include "ListNode.h"
#include "DeListNode.h"

using namespace std;

class Solution
{
private:
    bool NotOverlapInterval(vector<int> interval_1, vector<int> interval_2);
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals);
};

#endif
