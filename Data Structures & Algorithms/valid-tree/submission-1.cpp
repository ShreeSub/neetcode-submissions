class Solution {
public:
    unordered_set<int>seen;
    unordered_map<int,vector<int>>graph;
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()>n-1)
        return false;
        for(auto e:edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
       queue<pair<int,int>>q;
       q.push({0,-1});
       seen.insert(0);
       while(!q.empty())
       {
            auto [node,parent]=q.front();
            q.pop();
            for(auto nei:graph[node])
            {
                if(nei==parent)
                continue;
                if(seen.count(nei))
                return false;
                seen.insert(nei);
                q.push({nei,node});
            }         
       }
       return seen.size()==n;
    }
};
