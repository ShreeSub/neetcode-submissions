class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mp;
        for(auto c: s)
        {
            mp[c]++;
        }
        for(auto c:t)
        {
            if(!mp.contains(c))
            return false;
            mp[c]--;
            if(mp[c]<0)
            return false;
        }
        for(auto it:mp)
        {
            if(it.second!=0)
            return false;
        }
        return true;
    }
};
