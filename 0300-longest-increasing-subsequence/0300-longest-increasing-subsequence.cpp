class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        vector<int> after(n + 1, 0);
        
        for(int idx = n - 1; idx >= 0; idx--){
            vector<int> curr(n + 1, 0);
            for(int prev = idx - 1; prev >= -1; prev--){
                // not-take
                int len = after[prev + 1];
                //take
                if(prev == -1 || nums[prev] < nums[idx]){
                    len = max(len, 1 + after[idx + 1]);
                }
                curr[prev + 1] = len;
            }
            after = curr;
        }

        return after[0];
    }
};