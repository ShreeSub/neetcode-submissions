class TrieNode
{
    public:
    unordered_map<char, TrieNode*>children;
    bool wordEnd = false;
};

class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for(char c:word)
        {
            if(curr->children.find(c)==curr->children.end())
            {
                curr->children[c]=new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->wordEnd = true;
    }
    
    bool search(string word) {  return dfs(0, word, root);
    }
    bool dfs(int idx, string word, TrieNode* curr)
    {
        if(idx == word.size())
        {
            return curr->wordEnd;
        }
        char c = word[idx];
        if(c =='.')
        {
            for(auto& [ch, child]: curr->children)
            {
                if(dfs(idx+1, word, child))
                return true;
            }
            return false;
        }
        else{
            if(curr->children.find(c)==curr->children.end())
            return false;
    
        return dfs(idx+1, word, curr->children[c]);
        }
    }
};
