/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *tmp1, *tmp2, *t1, *t2;
        tmp1 = headA;
        tmp2 = headB;
        
        map<int,set<ListNode*>>M;
        pair<std::set<ListNode*>::iterator,bool> ret;
        while(tmp1 != NULL && tmp2 != NULL)
        {
            ret = M[tmp1->val].insert(tmp1);
            if(ret.second == false)
                return tmp1;
            
            ret = M[tmp2->val].insert(tmp2);
            if(ret.second == false)
                return tmp2;
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
        while(tmp1 != NULL)
        {
            ret = M[tmp1->val].insert(tmp1);
            if(ret.second == false)
                return tmp1;
            tmp1 = tmp1->next;  
        }
        while(tmp2 != NULL)
        {
            ret = M[tmp2->val].insert(tmp2);
            if(ret.second == false)
                return tmp2;
            tmp2 = tmp2->next;
        }
        return NULL;
    }
};