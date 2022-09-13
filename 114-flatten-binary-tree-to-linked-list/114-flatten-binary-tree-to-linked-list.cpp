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
    stack<TreeNode*> S;
    void flatten(TreeNode* root) {
        if(root == nullptr)
            return;
        pre(root);
        TreeNode *p,*r; 
        while(S.size() >=2 )
        {
            r = S.top();
            S.pop();
            p = S.top();
            S.pop();
            
            p->right = r;
            p->left = nullptr;
            
            S.push(p);
        }
        root = S.top();
        
    }
    
    void pre(TreeNode* root)
    {
        if(root != nullptr)
        {
            S.push(root);
            pre(root->left);
            pre(root->right); 
        }
    }
};