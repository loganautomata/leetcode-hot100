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
    void QuickSort(vector<int> &nums, pair<int, int> range); // range 是要分治排序的区间, 该区间左开右闭.
public:
    vector<int> sortArray(vector<int> &nums);
};

#endif
