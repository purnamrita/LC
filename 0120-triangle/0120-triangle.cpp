class Solution {
public:
    int helper(int r, int c, vector<vector<int>>& triangle, vector<vector<int>>& dp){
        int n = triangle.size();
        if(r == n - 1){
            return dp[r][c] = triangle[r][c];
        }

        if(dp[r][c] != -1){
            return dp[r][c];
        }

        int left = helper(r + 1, c, triangle, dp);
        int right = helper(r + 1, c + 1, triangle, dp);

        return dp[r][c] = triangle[r][c] + min(left, right);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return helper(0, 0, triangle, dp);
    }
};