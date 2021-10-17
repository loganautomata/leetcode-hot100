#include "solution.h"

using namespace std;

TreeNode *Solution::lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == p || root == q || root == nullptr)
        return root;

    TreeNode *left = this->lowestCommonAncestor(root->left, p, q);
    TreeNode *right = this->lowestCommonAncestor(root->right, p, q);

    if (left != nullptr && right != nullptr)
        return root;
    else
        return left == nullptr ? right : left;
}
