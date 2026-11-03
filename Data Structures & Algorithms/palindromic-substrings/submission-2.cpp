class Solution {
public:
    int countSubstrings(string s) {
        int res=0;
        int n= s.length();
        vector<vector<bool>>dp(n, vector<bool>(n,false));
        for(int j=0; j<n; j++)
        {
            for(int i=0; i<=j; i++)
            {
                if(s[i]==s[j] && (j-i<=2 || dp[i+1][j-1]))
                {
                    dp[i][j]=true;
                    res++;
                }
            }
        }
        return res;
    }
};
