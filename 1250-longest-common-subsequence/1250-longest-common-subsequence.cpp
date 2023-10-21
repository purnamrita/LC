class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
        
        for(int col = 0; col <= n2; col++){
            dp[0][col] = 0;
        }
        for(int row = 0; row <= n1; row++){
            dp[row][0] = 0;
        }

        for(int r = 1; r <= n1; r++){
            for(int c = 1; c <= n2; c++){
                if(text1[r - 1] == text2[c - 1]){
                    dp[r][c] = 1 + dp[r - 1][c - 1];
                }
                else{
                    dp[r][c] = max(dp[r - 1][c], dp[r][c - 1]);
                }
            }
        }

        return dp[n1][n2];
    }
};