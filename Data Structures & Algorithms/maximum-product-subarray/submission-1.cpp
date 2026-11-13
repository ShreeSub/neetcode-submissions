class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minSoFar = nums[0];
        int maxSoFar = nums[0];
        int maxVal = nums[0];
        int n = nums.size();
        for(int i=1; i<n; i++)
        {
            int tempMax = max(nums[i], max(nums[i]*maxSoFar, nums[i]*minSoFar)); 
            minSoFar = min(nums[i],min(nums[i]*maxSoFar, nums[i]*minSoFar));
            maxSoFar = tempMax;
            maxVal = max(maxVal, maxSoFar)
;
        }
        return maxVal;
    }
};
