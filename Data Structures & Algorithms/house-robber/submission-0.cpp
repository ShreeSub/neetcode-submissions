class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
        return 0;
        if(n==1)
        return nums[0];
        vector<int>dp(n+1,0);
        dp[0]=0;
        dp[1]=nums[0];
        for(int i=1; i<n; i++)
        {
            dp[i+1]= max(dp[i],nums[i]+dp[i-1]);
        }
        return dp[n];
        
    }
};
