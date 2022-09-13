class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)
            return 0;
        size_t ind;
        string r = "";
        r += s[0];
        
        int max=0;
        for(int i=1;i < s.size(); i++)
        {
            ind = r.find(s[i]);
            if(ind != string::npos)
            {
                if(max < r.size())
                    max = r.size();
                r.erase(0,ind+1);
                
            }
            r+=s[i];
            
            
        }
        if(r.size() > max)
            return r.size();
        return max;
        
    }
};