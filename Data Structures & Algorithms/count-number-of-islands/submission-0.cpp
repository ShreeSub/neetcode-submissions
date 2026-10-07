class Solution {
public:
    vector<vector<int>>dir = {{1,0},{0,1},{-1,0},{0,-1}};
    int rows,cols;
    int numIslands(vector<vector<char>>& grid) {
        rows= grid.size();
        cols = grid[0].size();
        int ans=0;
        for(int r=0; r<rows; r++)
        {
            for(int c=0; c<cols; c++)
            {
                if(grid[r][c]=='1')
                {
                    ans++;
                    dfs(grid,r,c);

                }
            }
        }
        return ans;
    }
    void dfs(vector<vector<char>>&grid, int r, int c)
    {
        if(r<0 ||r>=rows||c<0||c>=cols||grid[r][c]=='0')
        return;
        grid[r][c]='0';//marking it as visited
        for(auto it:dir)
        {
            dfs(grid, r+it[0], c+it[1]);
        }
    }
};
