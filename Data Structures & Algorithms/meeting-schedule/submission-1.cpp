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
        sort(intervals.begin(),intervals.end(),[](const Interval& a,const Interval& b){
            return a.start < b.start;
        });

        int lastEnd = INT_MIN;
        for(const auto& interval:intervals){
            if(interval.start >= lastEnd){
                lastEnd = interval.end;
            }
            else{
                return false;
            }
        }

        return true;
    }
};
