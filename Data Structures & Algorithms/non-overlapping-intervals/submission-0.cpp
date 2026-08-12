class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const auto& a,const auto& b){
            return a[1] < b[1];
        });
        int removals = 0;
        int lastend = INT_MIN;

        for(const auto& interval:intervals){
            if(interval[0] >= lastend){
                lastend = interval[1];
            }
            else{
                removals++;
            }
        }
        return removals;
    }
};
