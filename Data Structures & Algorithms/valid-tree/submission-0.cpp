class Solution {
public:
    unordered_set<int>seen;
    unordered_map<int,vector<int>>graph;
    bool validTree(int n, vector<vector<int>>& edges) {
        for(auto e:edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
       if(! dfs(0,-1))
       return false;
        return seen.size()==n;
    }
    bool dfs(int node, int parent)
    {
        if(seen.count(node))
        return false;
        seen.insert(node);
        for(auto neigh:graph[node])
        {
            if(neigh==parent)
            {
                continue;
            }
            if(!dfs(neigh,node))
            return false;
        }
        return true;
    }
};
