#include "solution.h"

using namespace std;

int Solution::dfs(TreeNode *cur)
{
    if (cur == nullptr)
        return 0;

    int left = dfs(cur->left);
    int right = dfs(cur->right);
    int sum = cur->val;
    int ans = cur->val;

    if (max(left, right) > 0)
        ans += max(left, right);
    if (left > 0)
        sum += left;
    if (right > 0)
        sum += right;
    if (sum > res)
        res = sum;
    
    return ans;
}

int Solution::maxPathSum(TreeNode *root)
{
    dfs(root);

    return res;
}
