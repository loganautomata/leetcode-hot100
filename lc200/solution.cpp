#include "solution.h"

using namespace std;

void Solution::dfs(int i, int j)
{
    if (i < 0 || i >= map.size() || j < 0 || j >= map[0].size() || map[i][j] == '0')
        return;
    
    map[i][j] = '0';
    dfs(i - 1, j);
    dfs(i + 1, j);
    dfs(i, j - 1);
    dfs(i, j + 1);

    return;
}

int Solution::numIslands(vector<vector<char>> &grid)
{
    map = grid;

    for (int i = 0; i < map.size(); i++)
    {
        for (int j = 0; j < map[0].size(); j++)
        {
            if (map[i][j] == '1')
            {
                dfs(i, j);
                res++;
            }
        }
    }

    return res;
}
