class Solution {
public:
    unordered_set<int>seen;
    unordered_map<int,vector<int>>graph;
    int countComponents(int n, vector<vector<int>>& edges) {
        for(auto e:edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        int ans=0;
        for(int i=0; i<n;i++)
        {
            if(!seen.count(i))
            ans++;
            dfs(i);
        }
        return ans;
    }
    void dfs(int node)
    {
        if(seen.count(node))
        return;
        seen.insert(node);
        for(auto nei:graph[node])
        {
            dfs(nei);
        }
    }
};
