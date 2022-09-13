class Solution {
public:
    bool static fun(int a, int b){
        return a%2<b%2;
    }
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> R;
        vector<int>::iterator it;

        for(it=nums.begin();it!=nums.end();it++)
        {
            R.push_back((*it));
        }
        sort(R.begin(),R.end(),fun);
        return R; 
    }
};