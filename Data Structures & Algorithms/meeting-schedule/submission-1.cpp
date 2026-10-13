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
    bool canAttendMeetings(vector<Interval>& intervals) {
        if(intervals.size()<2)
        return true;
        sort(intervals.begin(), intervals.end(), [](auto& x, auto& y) {
            return x.start < y.start;
        });
        for(int i=1; i<intervals.size(); i++)
        {
            auto firstEnd = intervals[i-1].end;
            auto secondStart = intervals[i].start;
            if(firstEnd>secondStart)
            return false;


        }
        return true;
    }
};
