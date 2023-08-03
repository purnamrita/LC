class Solution {
public:
    void helper(int idx, vector<int> &nums, vector<vector<int>> &ans){
        int n = nums.size();
        if(idx == n){
            ans.push_back(nums);
            return;
        }

        for(int i = idx; i < n; i++){
            swap(nums[idx], nums[i]);
            helper(idx + 1, nums, ans);
            swap(nums[idx], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(0, nums, ans);
        return ans;
    }
};