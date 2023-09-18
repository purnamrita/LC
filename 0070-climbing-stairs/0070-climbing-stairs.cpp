class Solution {
public:
    int climbStairsHelper(int n, vector<int> &dp) {
        if(n == 0){
            return 1;
        }
        if(n == 1){
            return 1;
        }
        int left, right;
        left = (dp[n - 1] != -1) ? dp[n - 1] : climbStairsHelper(n - 1, dp);
        right = (dp[n - 2] != -1) ? dp[n - 2] : climbStairsHelper(n - 2, dp);
        dp[n] = left + right;
        return left + right;
    }

    int climbStairs(int n){
        vector<int> dp(n + 1, -1);
        return climbStairsHelper(n, dp);
    }
};