class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       int res=0;
       unordered_set<int> s(nums.begin(),nums.end());
       for(auto num:nums)
       {
         if(!s.contains(num-1))
         {
            int len=1;
            while(s.contains(num+len))
            {
                len++;
            }
            res = max(res,len);
         }
       }
       return res; 
    }
};
