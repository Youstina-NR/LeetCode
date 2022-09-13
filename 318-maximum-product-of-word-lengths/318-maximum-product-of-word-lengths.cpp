class Solution {
public:
    
    
    int maxProduct(vector<string>& words) {
        vector<int> V(words.size());
        int res = 0,sub;
        for(int i = 0; i < words.size(); i++)
        {
            V[i] = 0;
            for(auto c : words[i])
            {
                V[i] |= 1 << (c - 'a');
            }
            
            for(int j = 0 ; j < i ; j++)
            {
                if((V[i] & V[j]) == 0 )
                {
                    sub = words[i].size()*words[j].size();
                    res = std::max(sub,res);
                }
            }
        }
        return res;
    }
};