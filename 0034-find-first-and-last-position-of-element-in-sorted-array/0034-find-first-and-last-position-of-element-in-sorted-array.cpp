class Solution {
public:
    int firstIdx(vector<int>& nums, int target){
        int l = 0;
        int r = nums.size() - 1;
        int ans = -1;

        while(l <= r){
            int m = l + (r - l) / 2;
            if(nums[m] == target){
                ans = m;
                r = m - 1;
            }
            else if(nums[m] > target){
                r = m - 1;
            }
            else{
                l = m + 1;
            }
        }

        return ans;
    }

    int lastIdx(vector<int>& nums, int target){
        int l = 0;
        int r = nums.size() - 1;
        int ans = -1;

        while(l <= r){
            int m = l + (r - l) / 2;
            if(nums[m] == target){
                ans = m;
                l = m + 1;
            }
            else if(nums[m] > target){
                r = m - 1;
            }
            else{
                l = m + 1;
            }
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        ans.push_back(firstIdx(nums, target));
        ans.push_back(lastIdx(nums, target));
        return ans;
    }
};