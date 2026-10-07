class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>res;
        backtrack(ans,res,nums,0,target);
        return ans;
    }
    void backtrack(vector<vector<int>>& ans, vector<int>&res, vector<int>&nums,int index, int target)
    {
        if(target==0)
        {
            ans.push_back(res);
            return;
        }
        if(target<0 || index >=nums.size())
        return;
        res.push_back(nums[index]);
        backtrack(ans,res,nums,index, target-nums[index]);
        res.pop_back();
        backtrack(ans,res,nums,index+1,target);
    }
};
