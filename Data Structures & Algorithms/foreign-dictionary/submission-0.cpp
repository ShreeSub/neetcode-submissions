class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char,vector<char>>graph;
        unordered_map<char,int>indegree;
        for(auto w:words)
        {
            for(auto c:w)
            {
                graph[c] = vector<char>();
                indegree[c]=0;
            }
        }
        for(int i=0; i<words.size()-1; i++)
        {
            string w1 = words[i];
            string w2 = words[i+1];
            int minlen = min(w1.length(),w2.length());
            if(w1.length()>w2.length() && w1.substr(0,minlen) ==w2.substr(0,minlen))
            {
                return "";
            }
            for(int j=0; j<minlen; j++)
            {
                if(w1[j]!=w2[j])
                {
                    graph[w1[j]].push_back(w2[j]);
                    indegree[w2[j]]++;
                    break;
                }
                
            }
        }
        queue<char>q;
        for(auto it:indegree)
        {
            if(it.second ==0)
            q.push(it.first);
        }
        string res;
        while(!q.empty())
        {
            char front = q.front();
            q.pop();
            res+=front;
            for(auto nei:graph[front])
            {
                indegree[nei]--;
                if(indegree[nei]==0)
                q.push(nei);
            }
        }
        return res.size()==indegree.size()?res:"";
    }
};
