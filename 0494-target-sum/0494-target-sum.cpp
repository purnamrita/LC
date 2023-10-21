class Solution {
public:
    int helper(vector<int>& nums, int diff, int target){
        int n = nums.size();
    
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));

        if(nums[0] == 0){
            dp[0][0] = 2;
        }
        else{
            dp[0][0] = 1;
        }

        if(nums[0] != 0 && nums[0] <= target){
            dp[0][nums[0]] = 1;
        }

        for(int row = 1; row < n; row++){
            dp[row][0] = 1;
            for(int tar = 0; tar <= target; tar++){
                int notPick = dp[row - 1][tar];
                int pick = 0;
                if(nums[row] <= tar){
                    pick = dp[row - 1][tar - nums[row]];
                }
                dp[row][tar] = pick + notPick;
            }
        }

        return dp[n - 1][target];
    }

    int help(vector<int>& nums, int diff){
        int n = nums.size();
        int totalSum = 0;
        for(int i = 0; i < n; i++){
            totalSum += nums[i];
        }
        if((totalSum < diff) || ((totalSum - diff) % 2 == 1)){
            return 0;
        }
        int target = (totalSum - diff) / 2;
        return helper(nums, diff, target);

    }


    int findTargetSumWays(vector<int>& nums, int diff) {
        return help(nums, diff);
    }
};