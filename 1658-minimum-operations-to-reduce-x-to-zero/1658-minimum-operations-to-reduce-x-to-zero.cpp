class Solution {
public:
    int minOperations(vector<int>& nums, int x) 
    {
        if(x == nums[0] || x == nums[nums.size()-1])
            return 1;
        if(x < nums[0] && x < nums[nums.size()-1])
            return -1;
        
        int asum = 0;
        for(auto e : nums)
            asum += e;
        if(asum == x)
            return nums.size();
        if(asum < x)
            return -1;
        
        int K = asum -x;
        int i = 0, j = 0;
        long long sum = 0;
        int maxLen = -1;

        while (j < nums.size()) 
        {
            sum += nums[j];
            
            if (sum == K) 
            {
                maxLen = max(maxLen, j-i+1);
            }
            else if (sum > K) 
            {
                while (sum > K) 
                {
                    sum -= nums[i];
                     i++;
                }
                if(sum == K)
                {
                  maxLen = max(maxLen, j-i+1);
                }
            }
            j++;
            
        }
        
        if(maxLen == -1)
            return -1 ;
        
        return (int)nums.size() - maxLen;
    
    
    }
};