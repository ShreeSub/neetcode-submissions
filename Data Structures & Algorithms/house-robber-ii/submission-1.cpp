class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)
        return nums[0];
        if(nums.size()==2)
        return max(nums[0],nums[1]);
        return max(findMax(vector<int>(nums.begin(), nums.end()-1)), findMax(vector<int>(nums.begin()+1, nums.end())));
        
    }
    int findMax(vector<int>nums)
    {
        vector<int>dp(nums.size(),0);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        int n= nums.size();
        for(int i=2; i<nums.size(); i++)
        {
            dp[i]= max(dp[i-1], nums[i]+dp[i-2]);
        }
        return dp[n-1];

    }
};
