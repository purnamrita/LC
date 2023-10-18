class Solution {
public:
    int helper(int i, int j, int m, int n, vector<vector<int>> &dp){
        if(i == 0  && j == 0){
            return dp[i][j] = 1;
        }
        if(i < 0 || j < 0){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int up = helper(i - 1, j, m, n, dp);
        int left = helper(i, j - 1, m, n, dp);

        return dp[i][j] = up + left;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(m - 1, n - 1, m, n, dp);
    }
};