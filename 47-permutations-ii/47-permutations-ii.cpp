class Solution {
public:
    vector<vector<int>> res;

    void getpermute(int i, vector<int> nums)
    {
        if(i == nums.size()-1)
        {
            res.push_back(nums);
            return;
        }
        int prev = -11;
        for(int j=i; j< nums.size(); j++)
        {
            if (j > i && nums[i] == nums[j])
                continue;
            if (prev != -11 && prev == nums[j]) {
                continue;
            }

            prev = nums[j];
            // swap the elements
            swap(nums[i], nums[j]);


            // recursion call
            getpermute(i + 1, nums);
        }

    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        getpermute(0,nums);  
        return res;
    }
};