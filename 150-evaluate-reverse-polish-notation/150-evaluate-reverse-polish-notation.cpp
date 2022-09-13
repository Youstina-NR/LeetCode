class Solution {
public:
    long long evalRPN(vector<string>& tokens) {
        stack<long> oprand;
        long oprand1,oprand2;
        string op = "+-*/";
        for(int i=0; i < tokens.size(); i++)
        {
            if(tokens[i].size() > 1 || op.find(tokens[i]) == string::npos)
                oprand.push(stoi(tokens[i]));
            else
            {
                oprand2 = oprand.top();
                oprand.pop();
                oprand1 = oprand.top();
                oprand.pop();
                if(tokens[i] == "+")
                    oprand.push(oprand1+oprand2);
                else if(tokens[i] == "-")
                    oprand.push(oprand1-oprand2);
                else if(tokens[i] == "*")
                    oprand.push(oprand1*oprand2);
                else 
                    oprand.push(oprand1/oprand2);
            }

        }
        return oprand.top(); 
        
    }
};