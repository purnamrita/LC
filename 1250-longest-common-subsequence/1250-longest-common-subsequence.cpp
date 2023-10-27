class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        for(int idx1 = 1; idx1 <= n1; idx1++){
            for(int idx2 = 1; idx2 <= n2; idx2++){
                if(text1[idx1 - 1] == text2[idx2 - 1]){
                    dp[idx1][idx2] = 1 + dp[idx1 - 1][idx2 - 1];
                }
                else{
                    dp[idx1][idx2] = max(dp[idx1 - 1][idx2], dp[idx1][idx2 - 1]);
                }
            }
        }
        return dp[n1][n2];
    }
};