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
class BSTIterator {
public:
    
    queue<TreeNode*> Q;
    
    BSTIterator(TreeNode* root) {
        inorderTraversal(root);
    }
    
    void inorderTraversal(TreeNode * n)
    {
        if(n != nullptr)
        {
            inorderTraversal(n->left);
            Q.push(n);
            inorderTraversal(n->right);
        }
    }
    
    int next() {
        if(hasNext())
        {
            int v = Q.front()->val;
            Q.pop();
            return v;
        }
        return -1;
    }
    
    bool hasNext() {
        if(Q.size() >= 1)
            return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */