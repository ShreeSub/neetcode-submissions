class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(n<2)
        return s;
        int startidx =0;
        int resLen =1;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i=0; i<n; i++)
        {
            dp[i][i]=true;
        }
        for(int i=0; i<n-1; i++)
        {
            if(s[i]==s[i+1])
            {
                dp[i][i+1]=true;
                if(resLen==1)
                {
                    startidx=i;
                    resLen = 2;
                }
            }
        }
        for(int len =3 ; len<=n; len++)//checking for lengths
        {
            for(int i=0; i<=n-len; i++)
            {
                int j= i+len-1;
                if(s[i]==s[j] && dp[i+1][j-1])
                {
                    dp[i][j]=true;
                    if(len>resLen)
                    {
                        resLen = len;
                        startidx=i;
                    }
                }
            }
        }
        return s.substr(startidx,resLen);
    }
};
