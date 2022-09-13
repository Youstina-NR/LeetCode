class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        bool f = true;
        string b = "({[";
        for(int i = 0; i < s.size(); i++)
        {
            if(b.find(s[i]) != string::npos)
            {
                st.push(s[i]);
            }
            else
            {
                if(st.empty())
                {
                    f = false;
                    break;
                }
                else if((st.top() == '(' && s[i] == ')')
                 || (st.top() == '[' && s[i] == ']')
                 || (st.top() == '{' && s[i] == '}'))
                {
                    st.pop();
                }
                else
                {
                    f = false;
                    break;
                }
            }
        }
        if(!st.empty())
            f = false;
        return f;    

    }
};