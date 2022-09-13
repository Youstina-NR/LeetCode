class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        map<int,int>M;
        vector<int> res;
        M[target-numbers[0]] = 0;
        for(int i=1; i < numbers.size(); i++)
        {
            if(M.find(numbers[i]) != M.end())
            {
                res.push_back(M[numbers[i]]+1);
                res.push_back(i+1);
                return res;
            }
            M[target-numbers[i]] = i;
        }
        return res;
    }
};