#include "solution.h"

using namespace std;

void Solution::dfs(TreeNode *cur)
{
    if (cur == nullptr)
        return;
    
    dfs(cur->left);
    res.push_back(cur->val);
    dfs(cur->right);

    return;
}

vector<int> Solution::inorderTraversal(TreeNode *root)
{
    dfs(root);

    return res;
}
