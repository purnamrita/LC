class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for(int i = 0; i < n; i++){
            sum += nums[i];
        }

        if(sum % 2){
            return false;
        }

        int target = sum / 2;

        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

        for(int row = 0; row < n; row++){
            dp[row][0] = true;
        }
        if(nums[0] <= target){
            dp[0][nums[0]] = true;
        }

        for(int row = 1; row < n; row++){
            for(int tar = 1; tar <= target; tar++){
                bool not_pick = dp[row - 1][tar];
                bool pick = false;
                if(nums[row] <= tar){
                    pick = dp[row - 1][tar - nums[row]];
                }
                dp[row][tar] = pick || not_pick;
            }
        }

        return dp[n - 1][target];
    }
};