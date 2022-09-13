class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> St;
        
        int i = 0;
        while(i< s.size())
        {
            if(St.empty() || St.top().first != s[i])
            {
                St.push(make_pair(s[i],1));
            }
            else
            {
                if((St.top().second + 1) % k == 0)
                    St.pop();
                else
                    St.top().second += 1;
            }
            
            i++;
        }
        
        string res = "";
        while(!St.empty())
        {
            res = string(St.top().second,St.top().first)+res;
            St.pop();
        }
        
        return res;
    }
};