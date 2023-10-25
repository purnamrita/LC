class Solution {
public:
    int firstOcc(vector<int>& nums, int target){
        int n = nums.size();
        int idx = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if(idx != n && nums[idx] == target){
            return idx;
        }
        return -1;
    }
    int lastOcc(vector<int>& nums, int target){
        int n = nums.size();
        int idx = upper_bound(nums.begin(), nums.end(), target) - nums.begin();

        if(idx > 0 && nums[idx - 1] == target){
            return idx - 1;
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2);
        ans[0] = firstOcc(nums, target);
        ans[1] = lastOcc(nums, target);
        return ans;
    }
};