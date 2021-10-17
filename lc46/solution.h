#ifndef SOLUTION_H
#define SOLUTION_H

#include <sstream>
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
    vector<vector<int>> res;
    void dfs(unordered_set<int> nums, vector<int> ans);

public:
    vector<vector<int>> permute(vector<int> &nums);
};

#endif
