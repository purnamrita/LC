class Solution {
public:
    int helper(int i, int j, vector<int>& cuts, vector<vector<int>> &dp){
        if(i > j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int mini = INT_MAX;
        for(int idx = i; idx <= j; idx++){
            int steps = cuts[j + 1] - cuts[i - 1] + helper(i, idx - 1, cuts, dp) + helper(idx + 1, j, cuts, dp);
            mini = min(mini, steps);
        }
        return dp[i][j] = mini;
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        int c = cuts.size();
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(c, vector<int>(c, -1));
        return helper(1, c - 2, cuts, dp);
    }
};