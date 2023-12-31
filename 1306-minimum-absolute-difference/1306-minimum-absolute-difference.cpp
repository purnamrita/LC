class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int minDiff = INT_MAX;
        for(int i = 1; i < arr.size(); i++){
            minDiff = min(minDiff, arr[i] - arr[i - 1]);
        }
        vector<vector<int>> ans;
        for(int i = 0; i < arr.size() - 1; i++){
            if(arr[i + 1] - arr[i] == minDiff){
                ans.push_back({arr[i], arr[i + 1]});
            }
        }
        return ans;
    }
};