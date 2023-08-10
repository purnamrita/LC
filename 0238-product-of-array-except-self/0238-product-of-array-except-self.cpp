class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // [1, 2, 3, 4] pro = 24
        // 24   12  8  6

        // [1, 2, 3, 4]
        // prefix
        // [1, 1, 2, 6]
        // suffix
        // [  24  ,12   ,4  ,1]

        // p -> [1, 1, 2, 6]
        // s -> [24, 12, 4, 1]
        // ans -?[24, 12, 8, 6]

        // time: O(n + n + n) = O(n)
        // space: O(n + n) = O(n)

        int n = nums.size();
        vector<int> prefix(n);
        vector<int> suffix(n);
        prefix[0] = 1;
        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }
        suffix[n - 1] = 1;
        for(int i = n - 2; i >= 0; i--){
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }

        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            ans[i] = prefix[i] * suffix[i];
        }

        return ans;
    }
};