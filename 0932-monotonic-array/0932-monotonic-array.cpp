class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();

        if(nums[n - 1] - nums[0] < 0){
            reverse(nums.begin(), nums.end());
        }

        for(int i = 1; i < n; i++){
            if(nums[i] - nums[i - 1] < 0){
                return false;
            }
        }

        return true;
    }
};