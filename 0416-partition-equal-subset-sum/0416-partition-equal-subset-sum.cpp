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
        vector<bool> prev(target + 1, false);
        if(nums[0] <= target){
            prev[nums[0]] = true;
        }

        for(int row = 1; row < n; row++){
            vector<bool> curr(target + 1, false);
            curr[0] = true;
            for(int tar = 1; tar <= target; tar++){
                bool not_pick = prev[tar];
                bool pick = false;
                if(nums[row] <= tar){
                    pick = prev[tar - nums[row]];
                }
                curr[tar] = pick || not_pick;
            }
            prev = curr;
        }

        return prev[target];
    }
};