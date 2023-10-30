class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int maxLen = 1;

        for(int idx = 1; idx < n; idx++){
            for(int prev = 0; prev < idx; prev++){
                if(nums[prev] < nums[idx]){
                    dp[idx] = max(dp[idx], dp[prev] + 1);
                }
            }
            maxLen = max(maxLen, dp[idx]);
        }

        return maxLen;
    }
};