class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n == 1){
            return 0;
        }
        sort(intervals.begin(), intervals.end());

        int res = 0;

        for(int i = 0; i < n - 1; i++){
            if(intervals[i][1] > intervals[i + 1][0]){
                if(intervals[i][1] < intervals[i + 1][1]){
                    intervals[i + 1] = intervals[i];
                }
                res++;
            }
        }

        return res;
    }
};