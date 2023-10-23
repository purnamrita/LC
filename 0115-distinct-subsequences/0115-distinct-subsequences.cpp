class Solution {
public:
    int helper(string s, string t, int idx1, int idx2, vector<vector<int>> &dp){
        if(idx2 < 0){
            return 1;
        }
        if(idx1 < 0){
            return 0;
        }
        if(dp[idx1][idx2] != -1){
            return dp[idx1][idx2];
        }
        if(s[idx1] == t[idx2]){
            return dp[idx1][idx2]  = helper(s, t, idx1 - 1, idx2 - 1, dp) + helper(s, t, idx1 - 1, idx2, dp);
        }
        else{
            return dp[idx1][idx2] = helper(s, t, idx1 - 1, idx2, dp);
        }
    }
    int numDistinct(string s, string t) {
        int slen = s.length();
        int tlen = t.length();
        vector<vector<int>> dp(slen, vector<int>(tlen, -1));
        return helper(s, t, slen - 1, tlen - 1, dp);
    }
};