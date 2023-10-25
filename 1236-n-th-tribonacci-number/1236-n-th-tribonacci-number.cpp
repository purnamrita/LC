class Solution {
public:
    int helper(int idx, vector<int> &dp){
        if(idx == 0){
            return 0;
        }
        if(idx == 1 || idx == 2){
            return 1;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        return dp[idx] = helper(idx - 1, dp) + helper(idx - 2, dp) + helper(idx - 3, dp);
    }
    int tribonacci(int n) {
        vector<int> dp(n + 1, -1);
        return helper(n, dp);
    }
};