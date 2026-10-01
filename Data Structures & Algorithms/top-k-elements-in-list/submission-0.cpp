class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto num:nums)
        {
            mp[num]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>heap;
        for(auto it:mp)
        {
            heap.push({it.second,it.first}); //so that min is used for frequency
            if(heap.size()>k)
            {
                heap.pop();
            }
        }
        vector<int>res;
        while(!heap.empty())
        {
            res.push_back(heap.top().second);
            heap.pop();
        }
        return res;
    }
};
