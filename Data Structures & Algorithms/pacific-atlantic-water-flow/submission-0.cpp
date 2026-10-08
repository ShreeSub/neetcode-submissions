class Solution {
public:
    int rows,cols;
    vector<vector<int>>dir = {{1,0},{-1,0},{0,1},{0,-1}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size();
        cols= heights[0].size();
        vector<vector<int>>pacific(rows,vector<int>(cols,0));
        vector<vector<int>>atlantic(rows,vector<int>(cols,0));
        vector<vector<int>>res;
        for(int c=0;c<cols;c++)
        {
            dfs(heights,pacific,0,c);
            dfs(heights,atlantic,rows-1,c);
        }
        for(int r=0; r<rows;r++)
        {
            dfs(heights,pacific,r,0);
            dfs(heights,atlantic,r,cols-1);
        }

        for(int r=0; r<rows;r++)
        {
            for(int c=0; c<cols;c++)
            {
                if(pacific[r][c]&&atlantic[r][c])
                {
                    res.push_back({r,c});
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<int>>&heights, vector<vector<int>>& ocean,  int r, int c)
    {
        ocean[r][c]=1;
        for(auto it:dir)
        {
            int newR=r+it[0];
            int newC= it[1]+c;
            if(newR>=0 && newR<rows&&newC>=0 && newC<cols&& !ocean[newR][newC] && heights[newR][newC]>=heights[r][c])
            {
                dfs(heights,ocean,newR,newC);
            }
        }
    }
};
