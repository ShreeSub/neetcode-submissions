class Solution {
public:
    unordered_set<int>seen;
    unordered_map<int,vector<int>>graph;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses,0);
        for(auto it:prerequisites)
        {
            indegree[it[0]]++;
            graph[it[1]].push_back(it[0]);
        }
        queue<int>q;
        for(int i=0; i<numCourses;i++)
        {
            if(indegree[i]==0)
            q.push(i);
        }
        int finish=0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            finish++;
            for(auto nei:graph[node])
            {
                indegree[nei]--;
                if(indegree[nei]==0)
                q.push(nei);
            }
        }
        return finish ==numCourses;
    }
};
