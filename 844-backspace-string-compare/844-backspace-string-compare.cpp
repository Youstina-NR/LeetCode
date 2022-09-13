class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        size_t found = s.find("#");
        while(found != string::npos)
        {
            if(found>=1)
                s.erase(found-1,2);
            else
                s.erase(found,1);
            found = s.find("#");
        }

        found = t.find("#");
        while(found != string::npos)
        {
            if(found>=1)
                t.erase(found-1,2);
            else
                t.erase(found,1);
            found = t.find("#");
        }


        return s==t; 
    }
};