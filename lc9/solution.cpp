#include "solution.h"

using namespace std;

bool Solution::isPalindrome(int x)
{
    vector<int> arr;

    if (x < 0) return false; // 当x为负数时不对称

    // 将x的各个位的数转为数组
    for (int i = x; i != 0; i /= 10)
    {
        arr.push_back(i % 10);
    }

    // 判断x的各位是否对称
    for (int i = 0, j = arr.size() - 1; i < j; i++, j--)
    {
        if (arr[i] != arr[j]) return false;
    }

    return true;
}
