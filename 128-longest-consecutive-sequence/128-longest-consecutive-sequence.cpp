class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        sort(nums.begin(),nums.end());
        int l = 1, res = 1,i = 1;
        
        while(i < nums.size())
        {
            if(nums[i]- nums[i-1] == 1)
            {
                l++;
            }
            else if(nums[i]- nums[i-1] == 0)
            {
                i++;
                continue;
            }
            else
            {
                res = max(res,l);
                l = 1;
            }
            i++;
        }
        return max(res,l);
    }
};