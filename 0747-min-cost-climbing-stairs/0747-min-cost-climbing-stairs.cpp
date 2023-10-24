class Solution {
public:
    int helper(int idx, vector<int>& cost, vector<int> &dp){
        int n = cost.size();
        if(idx >= n){
            return 0;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }

        return dp[idx] = cost[idx] + min(helper(idx + 1, cost, dp), helper(idx + 2, cost, dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 2, -1);
        return min(helper(0, cost, dp), helper(1, cost, dp));
    }
};