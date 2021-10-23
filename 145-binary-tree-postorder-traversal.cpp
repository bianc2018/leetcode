/*
* 给定一个二叉树，返回它的 后序 遍历。

示例:

输入: [1,null,2,3]  
   1
    \
     2
    /
   3 

输出: [3,2,1]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？
*/

#include <vector>
#include <stack>
using namespace std;

//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
 

class Solution {
public:
    //递归法
    vector<int> postorderTraversal1(TreeNode* root) {
        vector<int> res;
        if (NULL == root)
            return res;
        //dest.insert(dest.end(), src.begin(), src.end());
        vector<int> left = postorderTraversal(root->left);
        vector<int> right = postorderTraversal(root->right);

        res.insert(res.end(), left.begin(), left.end());
        res.insert(res.end(), right.begin(), right.end());
        res.push_back(root->val);
        return res;
    }

    //迭代法
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (NULL == root)
            return res;
        
        //标识已经遍历过的
        bool nodemap[200];
        memset(nodemap, false, sizeof(nodemap));

        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur || !st.empty())
        {
            //左入库
            if (cur)
            {
                st.push(cur);
                cur = cur->left;
                if (cur && cur->val == -101)
                    cur = NULL;
            }
            else
            {
                cur = st.top();
                if (cur->right&& cur->right->val!=-101)
                {
                    cur = cur->right;
                }
                else
                {
                    st.pop();
                    res.push_back(cur->val);
                    cur->val = -101;
                   // nodemap[cur->val + 100] = true;
                    cur = NULL;
                }
            }
        }
        return res;
    }
};

int main(int argc, char* argv[])
{
    //[1, null, 2, 3]
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node2 = new TreeNode(2,node3,NULL);
    TreeNode* root = new TreeNode(1, NULL, node2);
    Solution s;
    auto res = s.postorderTraversal(root);
}
