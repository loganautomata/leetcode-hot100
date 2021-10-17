#include "solution.h"

using namespace std;

bool Solution::lemonadeChange(vector<int>& bills)
{
    int dol_5_count = 0;
    int dol_10_count = 0;

    for (int &bill : bills)
    {
        switch (bill)
        {
        case 5:
            dol_5_count++;
            break;
        case 10:
            if (dol_5_count > 0)
            {
                dol_5_count--;
                dol_10_count++;
            }
            else
                return false;
            break;
        case 20:
            if (dol_10_count > 0 && dol_5_count > 0)
            {
                dol_5_count--;
                dol_10_count--;
            }
            else if (dol_5_count > 2)
            {
                dol_5_count-=3;
            }
            else
                return false;
            break;
        
        default:
            break;
        }
    }

    return true;
}
