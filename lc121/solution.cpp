#include "solution.h"

using namespace std;

int Solution::maxProfit(vector<int>& prices)
{
    int res = 0;
    int min_price = INT32_MAX;

    for (auto &price : prices)
    {
        int profit = price - min_price;
        if (profit > res) res = profit;
        if (price < min_price) min_price = price;
    }

    return res;
}
