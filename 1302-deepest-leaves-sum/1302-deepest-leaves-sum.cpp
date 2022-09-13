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
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        if(root == nullptr)
            return 0;
        int sum = -1;
        queue<TreeNode*>nodes;
        queue<int>H;
        int lastL = -1;
        nodes.push(root);
        H.push(0);
        TreeNode *n;
        int h;
        while(!nodes.empty())
        {
            n = nodes.front();
            h = H.front();
            if(h == lastL)
                sum += n->val;
            else
            {
                sum = n->val;
                lastL = h;
            }
            nodes.pop();
            H.pop();
            if(n->left)
            {
                nodes.push(n->left);
                H.push(h+1);
            }
            if(n->right != nullptr)
            {
                nodes.push(n->right);
                H.push(h+1);
            }
           }
            return sum;
    }
};