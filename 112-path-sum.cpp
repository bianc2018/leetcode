/*
*给你二叉树的根节点 root 和一个表示目标和的整数 targetSum ，
判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和 targetSum 。

叶子节点 是指没有子节点的节点。
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
#include <stack>
using namespace std;

class Solution {
    bool hasPathSumChild(TreeNode* root, int val, int targetSum) {
        if (NULL == root->left && NULL == root->right)
        {
            return val == targetSum;
        }
        if (root->left && hasPathSumChild(root->left, val + root->left->val, targetSum))
            return true;
        if (root->right && hasPathSumChild(root->right, val + root->right->val, targetSum))
            return true;
        return false;
    }
public:
    bool hasPathSum1(TreeNode* root, int targetSum) {
        if (NULL == root)
            return false;
        return hasPathSumChild(root, root->val, targetSum);
    }
    //迭代
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (NULL == root)
            return false;

        TreeNode* cur = root,*pre=NULL;
        stack<TreeNode*>st;
        //st.push(root);
        int cur_val = 0;
        while (!st.empty() || cur)
        {
            if (cur)
            {
                st.push(cur);
                cur_val += cur->val;
                cur = cur->left;
            }
            else
            {
                cur = st.top();
                if (NULL == cur->left && NULL == cur->right)
                {
                    //continue;
                    if (cur_val == targetSum)
                        return true;
                }

                if (cur->right&& cur->right !=pre)
                {
                    cur = cur->right;
                    continue;
                }
                st.pop();
                cur_val -= cur->val;
                pre = cur;
                cur = NULL;
            }
        }
        return false;
    }
};

int main(int argc, char* argv[])
{
    TreeNode* node7 = new TreeNode(7);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node11 = new TreeNode(11, node7, node2);
    TreeNode* rnode4 = new TreeNode(4, node11, NULL);

    TreeNode* node1 = new TreeNode(1);
    TreeNode*  node4 = new TreeNode(4,NULL, node1);
    TreeNode* node13 = new TreeNode(13);
    TreeNode* node8 = new TreeNode(8, node13, node4);

    TreeNode* root = new TreeNode(5, rnode4, node8);
    Solution s;
    s.hasPathSum(root, 22);
    return 0;
}