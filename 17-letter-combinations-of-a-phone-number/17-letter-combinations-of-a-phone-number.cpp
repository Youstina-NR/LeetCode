class Solution {
public:
    map<char,string> M;
    vector<string> V;
    vector<string> Vt;
    void setM(string digits)
    {
        M['2'] = "abc";
        M['3'] = "def";
        M['4'] = "ghi";
        M['5'] = "jkl";
        M['6'] = "mno";
        M['7'] = "pqrs";
        M['8'] = "tuv";
        M['9'] = "wxyz";
        for(auto x : digits)
            Vt.push_back(M[x]);

    }
    
    void getV(int i,string r)
    {
        if( i == Vt.size() )
        {
            V.push_back(r);
            return ;
        }
       
        for(auto y : Vt[i])
        {   r += y;
            getV(i+1,r);
            r.pop_back();
        }  
        
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)
            return V;
        setM(digits);
        getV(0,"");
        return V;
        
    }
};