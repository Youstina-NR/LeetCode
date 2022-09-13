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
    
    TreeNode* r,*tmp;
    bool flag = false;
    void depth(TreeNode* n)
    {
        if(n != nullptr)
        {
            depth(n->left);
            if(!flag)
            {
                flag = true;
                r = new TreeNode(n->val);
                tmp = r;
            }
            else
            {
                tmp->right = new TreeNode(n->val);
                tmp = tmp->right;
            }
        
            depth(n->right);
        }
    }
    
    
    
    TreeNode* increasingBST(TreeNode* root) {
        tmp = r = nullptr;
        depth(root);
        return r;
    }
};