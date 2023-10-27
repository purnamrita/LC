class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();

        vector<int> left(n, INT_MAX);
        vector<int> right(n, INT_MAX);

        for(int i = 1; i < n; i++){
            left[i] = min(nums[i - 1], left[i - 1]);
        }
        for(int i = n - 2; i >= 0; i--){
            right[i] = min(right[i + 1], nums[i + 1]);
        }

        int ans = INT_MAX;
        for(int i = 0; i < n; i++){
            if(nums[i] > left[i] && nums[i] > right[i]){
                ans = min(ans, nums[i] + left[i] + right[i]);
            }
        }

        if(ans == INT_MAX){
            return -1;
        }
        return ans;


    }
};