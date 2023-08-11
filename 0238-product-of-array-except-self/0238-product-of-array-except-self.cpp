class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefix(n);
        prefix[0] = 1;
        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }
        vector<int> ans(n);
        int suffix = 1;
        ans[n - 1] = prefix[n - 1] * suffix;

        for(int i = n - 2; i >= 0; i--){
            suffix *= nums[i + 1];
            ans[i] = prefix[i] * suffix;
        }

        return ans;
    }
};