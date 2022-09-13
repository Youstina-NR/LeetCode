class Solution {
public:
   bool find132pattern(vector<int>& nums) {
        if (nums.size() < 3) 
            return false;
        
        stack<int> stk;
        vector<int> min_val;
        min_val.push_back(nums[0]);

        for (size_t i = 1; i < nums.size(); i++) 
        {
            min_val.push_back(min(min_val[i - 1], nums[i]));
        }
        for (size_t j = nums.size() - 1; j > 0; j--) 
        {
            if (nums[j] <= min_val[j]) 
            {
                continue;
            }
            while (!stk.empty() and stk.top() <= min_val[j]) 
            {
                stk.pop();
            }
            if (!stk.empty() and stk.top() < nums[j]) 
            {
                return true;
            }
            stk.push(nums[j]);
        }
        return false;
    }
};