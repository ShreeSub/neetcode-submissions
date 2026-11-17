class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool>dp(n+1,false);
        dp[0]=true; //empty string can be divided
        unordered_set<string>st(wordDict.begin(),wordDict.end());
        int maxlen =0;
        for(int i=0; i<wordDict.size(); i++)
        {
            maxlen = max(maxlen,(int)wordDict[i].size());
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=i-1; j>=max(0, i-maxlen);j--)
            {
                if(dp[j]&& st.contains(s.substr(j,i-j)))
                {
                    dp[i]=true;
break;
                }
            }
        }
        return dp[n];
    }
};
