class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
       map<int,int>M;
        vector<int> csum(nums.size(),0); 
        csum[0] = nums[0];
        int sum = nums[0], max = 0,b =0;
        M[nums[0]] = 0;
        for(int i=1; i< nums.size(); ++i)
        {
            csum[i] = csum[i-1] + nums[i];
            
            if(M.find(nums[i]) != M.end() && M[nums[i]] >= b )
            {
                if(sum > max)
                    max = sum;
                b = M[nums[i]] + 1;
                sum = csum[i]-csum[b - 1] ;
                
            }
            else
                sum += nums[i];
            M[nums[i]] = i;
            
        }
        if(sum > max)
                    max = sum;
        return max;
    }
};