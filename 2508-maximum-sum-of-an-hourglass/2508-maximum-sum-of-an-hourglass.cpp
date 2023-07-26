class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> prefixSum(m, vector<int>(n + 1, 0));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                prefixSum[i][j + 1] = prefixSum[i][j] + grid[i][j];
            }
        }
        
        int ans = INT_MIN;
        for(int i = 1; i < m - 1; i++){
            for(int j = 1; j < n - 1; j++){
                int currEle = grid[i][j];
                int currHourSum = currEle + (prefixSum[i - 1][j + 2] - prefixSum[i - 1][j - 1]) + (prefixSum[i + 1][j + 2] - prefixSum[i + 1][j - 1]);
                ans = max(ans, currHourSum);
            }
        }
        return ans;
    }
};