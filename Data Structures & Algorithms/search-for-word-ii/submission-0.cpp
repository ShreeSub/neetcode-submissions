class TrieNode
{
    public:
    unordered_map<char,TrieNode*>children;
    bool wordEnd;
    TrieNode() : wordEnd(false){}
    void addWord(string word)
    {
        TrieNode* curr = this;
        for(char c:word)
        {
            if(!curr->children.count(c))
            {
                curr->children[c]= new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->wordEnd = true;
    }
};
class Solution {
    unordered_set<string>res;
    vector<vector<bool>>seen;
    int rows, cols;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for(string w:words)
        {
            root->addWord(w);
        }
        rows = board.size();
         cols = board[0].size();
        seen.assign(rows,vector<bool>(cols,false));
        for(int r=0; r<rows;r++)
        {
            for(int c=0; c<cols; c++)
            {
                dfs(board,r,c,root,"");
            }
        }
        return vector<string>(res.begin(),res.end());
        
    }
    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* curr, string word)
    {
        if(r<0||r>=rows || c<0 || c>=cols || seen[r][c]|| !curr->children.count(board[r][c]))
        { return;
        }
        seen[r][c]=true;
        curr = curr->children[board[r][c]];
        word+=board[r][c];
        if(curr->wordEnd)
        {
            res.insert(word);
        }
        dfs(board, r+1, c, curr, word);
        dfs(board, r-1, c, curr, word);
        dfs(board, r, c+1, curr, word);
        dfs(board, r, c-1, curr, word);
        seen[r][c]= false;
    }
};
