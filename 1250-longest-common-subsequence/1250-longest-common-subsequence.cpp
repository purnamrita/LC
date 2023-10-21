class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));

        vector<int> prev(n2 + 1);
        
        for(int col = 0; col <= n2; col++){
            prev[col] = 0;
        }

        for(int r = 1; r <= n1; r++){
            vector<int> curr(n2 + 1);
            for(int c = 1; c <= n2; c++){
                if(text1[r - 1] == text2[c - 1]){
                    curr[c] = 1 + prev[c - 1];
                }
                else{
                    curr[c] = max(prev[c], curr[c - 1]);
                }
            }
            prev = curr;
        }

        return prev[n2];
    }
};