class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> V(nums.size());
        V[0] = nums[0];
        for(int i = 1; i < nums.size(); i++ )
        {
            V[i] = V[i-1] + nums[i];
        }
        return V;
    }
};