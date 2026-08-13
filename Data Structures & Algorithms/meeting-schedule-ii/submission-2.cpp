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
        if(intervals.size() == 0) return 0;

        //Sort meetings by start time
        sort(intervals.begin(),intervals.end(),[](const Interval& a,const Interval& b){
            return a.start < b.start;
        });

        // Min Heap: Stores the end time of each ongoing meeting
        priority_queue<int,vector<int>,greater<int>> pq;

        for(const auto& interval:intervals){
            // If the earliest-ending meeting was finished,
            // reuse the room
            if(!pq.empty() && pq.top() <= interval.start){
                pq.pop();
            }
            pq.push(interval.end);
        }

        return pq.size();

    }
};
