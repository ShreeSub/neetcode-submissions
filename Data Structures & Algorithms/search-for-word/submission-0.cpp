class Solution {
public:
    set<pair<int,int>>seen;
    int rows,cols;
    vector<vector<int>>dir = {{1,0},{0,1},{-1,0},{0,-1}};
    bool exist(vector<vector<char>>& board, string word) {
        rows= board.size();
        cols = board[0].size();
        for(int r=0; r<rows; r++)
        {
            for(int c=0; c<cols; c++)
            {
               if( dfs(board,word,r,c,0))
               {
                return true;
               }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, string& word, int r, int c, int i)
    {
        if(i==word.length())
        {
            return true;
        }
        if(r<0||r>=rows||c<0||c>=cols||board[r][c]!=word[i]||seen.contains({r,c}))
        return false;
    
    seen.insert({r,c});
    for(auto it:dir)
    {
        if(dfs(board,word,r+it[0],c+it[1],i+1))
        return true;
    }
    seen.erase({r,c});
    return false;
    }
};
