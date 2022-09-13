class Solution {
public:
    string reverseParentheses(string s) {
        
        size_t f,l;
        f = s.find_last_of("(");
        while(f != string::npos )
        {
            l = s.find_first_of(")",f+1);
            
            reverse(s.begin()+f+1,s.begin()+l);
            s.erase(l,1);
            s.erase(f,1);
    
            f = s.find_last_of("(");
        }
        return s;
    }
};