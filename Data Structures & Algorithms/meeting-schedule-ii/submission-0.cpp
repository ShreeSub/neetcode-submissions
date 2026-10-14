/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int>start,end;
        for(auto it:intervals)
        {
            start.push_back(it.start);
            end.push_back(it.end);
        }
        sort(start.begin(),start.end());
        sort(end.begin(), end.end());
        int res=0,count=0,s=0,e=0;
        while(s<intervals.size())
        {
            if(start[s]<end[e])
            {
                count++; //a meeting started before a meeting ended, need a room
                s++;
            }else{
                count--;//a meeting ended before next start, room is freed
                e++;
            }
            res = max(res,count);
        }
        return res;
    }
};
