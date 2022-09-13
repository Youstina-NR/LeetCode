/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
   Node* connect(Node* root) {
        if(root == NULL )
            return root;
        queue<Node*>Q;
        queue<int>nodeH;
        Node *f,*s;
        Q.push(root);
        nodeH.push(0);
        int hf,hs;
        hf =0; f= root;
        while(!Q.empty())
        {
            s = Q.front();
            hs = nodeH.front();
            if( hs == 0)
                s->next = NULL;
            else if(hf == hs)
                f->next = s;
            else
                f->next = NULL;
            
            if(s->left != NULL)
            {
                Q.push(s->left);
                nodeH.push(hs+1);
            }
            if(s->right != NULL)
            {
                Q.push(s->right);
                nodeH.push(hs+1);
            }
            Q.pop();
            nodeH.pop();
            hf = hs;
            f = s;
        }
        f->next = NULL;
        return root;
    }
};