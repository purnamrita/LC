class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        for(int i = 0; i < n; i++){
            if(i == 0){
                ans[i] = 1;
            }
            else{
                ans[i] = ans[i - 1] * nums[i - 1];
            }
        }

        int suff = 1;
        for(int i = n - 1; i >= 0; i--){
            if(i == n - 1){
                ans[i] *= 1;
                suff = 1;
            }
            else{
                ans[i] *= (suff * nums[i + 1]);
                suff = suff * nums[i + 1];
            }
        }

        return ans;
    }
};