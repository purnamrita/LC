class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prev(n);

        for(int c = 0; c < n; c++){
            prev[c] = matrix[n - 1][c];
        }

        for(int r = n - 2; r >= 0; r--){
            vector<int> curr(n);
            for(int c = 0; c < n; c++){
                int ld = INT_MAX;
                int down = INT_MAX;
                int rd = INT_MAX;
                if(c > 0){
                    ld = prev[c - 1];
                }
                down = prev[c];
                if(c < n - 1){
                    rd = prev[c + 1];
                }
                curr[c] = matrix[r][c] + min(ld, min(down, rd));
            }
            prev = curr;
        }

        int mini = INT_MAX;
        for(int c = 0; c < n; c++){
            mini = min(mini, prev[c]);
        }
        return mini;
    }
};