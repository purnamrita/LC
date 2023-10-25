class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;

        vector<int> dp(n, 1);

        for(int idx = 0; idx < n; idx++){
            for(int prev = 0; prev < idx; prev++){
                if(nums[prev] < nums[idx]){
                    dp[idx] = max(dp[idx], dp[prev] + 1);
                }
            }
            maxi = max(maxi, dp[idx]);
        }

        return maxi;
    }
};