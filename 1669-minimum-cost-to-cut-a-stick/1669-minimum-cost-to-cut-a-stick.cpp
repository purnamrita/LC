class Solution {
public:

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        int c = cuts.size();
        vector<vector<int>> dp(c, vector<int>(c, 0));
        
        for(int i = c - 2; i >= 1; i--){
            for(int j = 1; j <= c - 2; j++){
                if(i > j){
                    continue;
                }
                int mini = INT_MAX;
                for(int idx = i; idx <= j; idx++){
                    int steps = cuts[j + 1] - cuts[i - 1] + dp[i][idx - 1] + dp[idx + 1][j];
                    mini = min(mini, steps);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][c - 2];
    }
};