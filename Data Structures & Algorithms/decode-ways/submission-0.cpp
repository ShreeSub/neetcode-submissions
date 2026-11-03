class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int>dp(n+1,0);
        dp[0]=1 ;//base case: empty string; there is one way to decode it
        dp[1]= s[0]=='0'?0:1;//if 0 can't be decoded otherwise only one way as single character
        for(int i=2; i<=n; i++)
        {
            if(s[i-1]>='1')
            dp[i]=dp[i-1];//if taking single char
            if(s[i-2]=='1'||s[i-1]< '7' && s[i-2]=='2')
            dp[i]+=dp[i-2];//consider it as two digits;combining s[i]and s[i-1]
        }
        return dp[n];
    }
};
