class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> prev(n);

        for(int r = n - 1; r >= 0; r--){
            vector<int> curr(n);
            for(int c = 0; c <= r; c++){
                if(r == n - 1){
                    curr[c] = triangle[r][c];
                }
                else{
                    curr[c] = triangle[r][c] + min(prev[c], prev[c + 1]);
                }
            }
            prev = curr;
        }

        return prev[0];
    }
};