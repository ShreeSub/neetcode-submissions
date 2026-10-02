class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        int n =nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0; i<n; i++)
        {
            if(nums[i]>0)
            break;
            if(i>0 && nums[i]==nums[i-1])
            continue;
            int left=i+1, right =n-1;
            while(left<right)
            {
                if(nums[i]+nums[left]+nums[right]>0)
                right--;
                else if (nums[i]+nums[left]+nums[right]<0)
                left++;
                else{
                    res.push_back({nums[i],nums[left], nums[right]});
                    left++;
                    right--;
                    while(left<right && nums[left]==nums[left-1])
                    left++;
                }

            }
        }
        return res;
    }
};
