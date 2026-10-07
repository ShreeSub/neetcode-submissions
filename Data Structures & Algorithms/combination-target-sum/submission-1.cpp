class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>res;
        sort(nums.begin(), nums.end());
        backtrack(ans,res,nums,0,target,0);
        return ans;
    }
    void backtrack(vector<vector<int>>& ans, vector<int>&res, vector<int>&nums,int index, int target, int total)
    {
        if(target==total)
        {
            ans.push_back(res);
            return;
        }
        for(int j=index; j<nums.size();j++)
        {
            if(nums[j]+total>target)
            return;
            res.push_back(nums[j]);
            backtrack(ans,res,nums,j,target,total+nums[j]);
            res.pop_back();
        }
    }
};
