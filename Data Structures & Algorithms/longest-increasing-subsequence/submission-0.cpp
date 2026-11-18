class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n= nums.size();
        vector<int>t(n,1);
        int res = 1;
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(nums[j]<nums[i]&& 1+t[j]>t[i])
                {
                    t[i]=1+t[j];
                    res = max(res, t[i]);
                }
            }
        }
        return res;
        
    }
};
