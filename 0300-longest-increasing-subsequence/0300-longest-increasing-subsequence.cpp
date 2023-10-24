class Solution {
public:
    int helper(int idx, int prev, vector<int>& nums, vector<vector<int>> &dp){
        if(idx == nums.size()){
            return 0;
        }
        if(dp[idx][prev] != -1){
            return dp[idx][prev];
        }
        // not-take
        int len = helper(idx + 1, prev, nums, dp);
        //take
        if(prev == 0 || nums[prev - 1] < nums[idx]){
            len = max(len, 1 + helper(idx + 1, idx + 1, nums, dp));
        }
        return dp[idx][prev] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // idx -> 0 to n - 1 (n)
        // prev -> -1 to n - 1 -> shift -> make -> 0 to n (n + 1)
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return helper(0, 0, nums, dp);
    }
};