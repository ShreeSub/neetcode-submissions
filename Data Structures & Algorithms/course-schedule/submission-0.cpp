class Solution {
public:
    unordered_set<int>seen;
    unordered_map<int,vector<int>>graph;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i=0; i<numCourses; i++)
        {
            graph[i] ={};
        }
        for(auto it:prerequisites)
        {
            graph[it[0]].push_back(it[1]);
        }
        for(int i=0; i<numCourses; i++)
        {
            if(!dfs(i))
            return false;
        }
        return true;
    }
    bool dfs(int i)
    {
        if(seen.contains(i))
        return false;
       
        if(graph[i].empty())//no preReq
        return true;
         seen.insert(i);
        for(auto nei:graph[i])
        {   if(!dfs(nei))
        return false;

        }
        seen.erase(i);//erase to independently try other neighbours and backtrack
        graph[i].clear();//helps to not traverse again path from i if some other course has i as pre req
        return true;

    }
};
