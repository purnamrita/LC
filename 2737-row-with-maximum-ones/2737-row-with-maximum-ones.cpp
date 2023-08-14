class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> cnt(n);
        int ans = 0;
        int row = 0;

        for(int i = 0; i < n; i++){
            int c = 0;
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 1){
                    c++;
                }
            }
            cnt[i] = c;
            if(c > ans){
                ans = c;
                row = i;
            }
        }

        return {row, ans};
    }
};