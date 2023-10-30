class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> cnt(n, 1);
        int maxLen = 1;

        for(int idx = 1; idx < n; idx++){
            for(int prev = 0; prev < idx; prev++){
                if(nums[prev] < nums[idx]){
                    if(dp[prev] + 1 > dp[idx]){
                        dp[idx] = dp[prev] + 1;
                        cnt[idx] = cnt[prev];
                    }
                    else if(dp[prev] + 1 == dp[idx]){
                        cnt[idx] += cnt[prev];
                    }
                }
            }
            maxLen = max(maxLen, dp[idx]);
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            if(dp[i] == maxLen){
                ans += cnt[i];
            }
        }
        return ans;
    }
};