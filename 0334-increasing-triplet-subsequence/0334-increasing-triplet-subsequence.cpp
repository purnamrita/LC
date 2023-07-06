class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        int left = INT_MAX;
        int mid = INT_MAX;

        for(int i = 0; i < n; i++){
            if(nums[i] > left && nums[i] < mid){
                mid = nums[i];
            }
            else if(nums[i] > left && nums[i] > mid){
                return true;
            }
            else if(nums[i] < mid){
                left = nums[i];
            }
        }
        return false;
    }
};