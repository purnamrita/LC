class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for(int r = n - 1; r >= 0; r--){
            for(int c = 0; c <= r; c++){
                if(r == n - 1){
                    dp[r][c] = triangle[r][c];
                }
                else{
                    dp[r][c] = triangle[r][c] + min(dp[r + 1][c], dp[r + 1][c + 1]);
                }
            }
        }

        return dp[0][0];
    }
};