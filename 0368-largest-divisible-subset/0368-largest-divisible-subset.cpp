class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> hash(n);
        for(int i = 0; i < n; i++){
            hash[i] = i;
        }
        int maxIdx = 0;
        int maxLen = 1;

        for(int idx = 1; idx < n; idx++){
            int prev;
            for(prev = 0; prev < idx; prev++){
                if(nums[idx] % nums[prev] == 0 && dp[idx] < dp[prev] + 1){
                    dp[idx] = dp[prev] + 1;
                    hash[idx] = prev;
                }
            }
            if(dp[idx] > maxLen){
                maxLen = dp[idx];
                maxIdx = prev;
            }
        }

        vector<int> ans;
        ans.push_back(nums[maxIdx]);
        while(maxIdx != hash[maxIdx]){
            ans.push_back(nums[hash[maxIdx]]);
            maxIdx = hash[maxIdx];
        }
        return ans;
    }
};