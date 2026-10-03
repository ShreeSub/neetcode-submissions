class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        string res;
        auto& p = mp[key];
        int left=0, right = p.size()-1;
        while(left<=right)
        {
            int mid = left+(right-left)/2;
            if(p[mid].first <= timestamp)
            {
                res = p[mid].second;
                left=mid+1;
            }else{
                right =mid-1;
            }
        }
        return res;
    }
};

