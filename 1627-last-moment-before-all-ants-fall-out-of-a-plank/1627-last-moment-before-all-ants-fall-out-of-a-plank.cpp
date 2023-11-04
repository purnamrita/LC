class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {

        int time = INT_MIN;
        for(int i = 0; i < left.size(); i++){
            time = max(time, (left[i] - 0));
        }
        for(int i = 0; i < right.size(); i++){
            time = max(time, (n - right[i]));
        }

        return time;
    }
};