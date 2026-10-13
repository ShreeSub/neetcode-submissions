class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       sort(intervals.begin(),intervals.end());
        vector<vector<int>>res;
        res.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++)
        {
            int s = intervals[i][0];
            int e = intervals[i][1];
            int lastend = res.back()[1];
            if(s<=lastend)
            {
                res.back()[1]= max(lastend,e);
            }
            else{
                res.push_back({s,e});
            }
        }
        return res;
    }
};
