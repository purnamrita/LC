class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        int removals = 0;
        int prev = 0;
        int curr;

        for(curr = 1; curr < n; curr++){
            if(intervals[curr][0] >= intervals[prev][1]){
                prev = curr;
            }
            else{
                if(intervals[prev][1] > intervals[curr][1]){
                    prev = curr;
                }
                removals++;
            }
        }


        return removals;
    }
};