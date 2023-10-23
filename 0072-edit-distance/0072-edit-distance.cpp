class Solution {
public:
    int helper(int idx1, int idx2, string &word1, string &word2, vector<vector<int>> &dp){
        if(idx1 < 0){
            return idx2 + 1;
        }
        if(idx2 < 0){
            return idx1 + 1;
        }
        if(dp[idx1][idx2] != -1){
            return dp[idx1][idx2];
        }
        if(word1[idx1] == word2[idx2]){
            return dp[idx1][idx2] = helper(idx1 - 1, idx2 - 1, word1, word2, dp);
        }

        return dp[idx1][idx2] = 1 + min(
            helper(idx1, idx2 - 1, word1, word2, dp),  // insert
            min(helper(idx1 - 1, idx2, word1, word2, dp),  //delete
            helper(idx1 - 1, idx2 - 1, word1, word2, dp)) //replace
        );
    }

    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        return helper(n1 - 1, n2 - 1, word1, word2, dp);
    }
};