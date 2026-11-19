class Solution {
public:
vector<vector<int>>dp;
string s1,s2;
    int longestCommonSubsequence(string text1, string text2) {
       
       int m = text1.size();
       int n = text2.size(); 
       s1=text1;
       s2=text2;
       dp.resize(m,vector<int>(n,-1));
       return dfs(m-1,n-1);
    }
    int dfs( int i,int j)
    {
        if(i<0 ||j<0)
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        if(s1[i]==s2[j])
        return dp[i][j] = 1+dfs(i-1,j-1);
       return dp[i][j] = max(dfs(i-1,j),dfs(i,j-1));
    }
};
