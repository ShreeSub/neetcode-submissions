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
        if(intervals.size()==0)
        {
            return 0;
        }
        sort(intervals.begin(), intervals.end(), [](const auto&a, const auto& b){
            return a.start<b.start;
        });
        priority_queue<int, vector<int>, greater<int>>minheap;
        minheap.push(intervals[0].end);
        for(int i=1; i<intervals.size(); i++)
        {
            auto curr = intervals[i];
            auto earliest = minheap.top();
            minheap.pop();
            if(curr.start>=earliest)
            {
                earliest =curr.end;
            } else{
                minheap.push(curr.end);
            }
            minheap.push(earliest);
        }
        return minheap.size();
    }
};
