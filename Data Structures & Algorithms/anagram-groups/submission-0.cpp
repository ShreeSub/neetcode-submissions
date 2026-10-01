class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string, vector<string>>mp;
       for(auto s:strs) 
       {
            string ss=s;
            sort(ss.begin(),ss.end());
            mp[ss].push_back(s);
       }
       vector<vector<string>>ans;
       for(auto it:mp)
       {
            ans.push_back(it.second);
       }
       return ans;
    }
};
