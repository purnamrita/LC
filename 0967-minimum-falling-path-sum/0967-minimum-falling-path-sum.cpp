class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for(int c = 0; c < n; c++){
            dp[n - 1][c] = matrix[n - 1][c];
        }

        for(int r = n - 2; r >= 0; r--){
            for(int c = 0; c < n; c++){
                int ld = INT_MAX;
                int down = INT_MAX;
                int rd = INT_MAX;
                if(c > 0){
                    ld = dp[r + 1][c - 1];
                }
                down = dp[r + 1][c];
                if(c < n - 1){
                    rd = dp[r + 1][c + 1];
                }
                dp[r][c] = matrix[r][c] + min(ld, min(down, rd));
            }
        }

        int mini = INT_MAX;
        for(int c = 0; c < n; c++){
            mini = min(mini, dp[0][c]);
        }
        return mini;
    }
};