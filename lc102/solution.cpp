#include "solution.h"

using namespace std;

vector<vector<int>> Solution::levelOrder(TreeNode *root)
{
    vector<vector<int>> res;
    queue<TreeNode *> que;

    if (root != nullptr)
    {
        que.push(root);
    }

    while (!que.empty())
    {
        vector<int> temp(que.size());
        for (int i = 0; i < temp.size(); i++)
        {
            temp[i] = que.front()->val;
            if (que.front()->left != nullptr)
                que.push(que.front()->left);
            if (que.front()->right != nullptr)
                que.push(que.front()->right);
            que.pop();
        }
        res.push_back(temp);
    }

    return res;
}
