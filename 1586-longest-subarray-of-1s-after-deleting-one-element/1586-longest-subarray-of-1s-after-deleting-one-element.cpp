class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int cnt0 = 0;
        int ans = 0;

        while(r < n){
            if(nums[r] == 0){
                cnt0++;
            }
            if(cnt0 > 1){
                while(cnt0 > 1){
                    if(nums[l] == 0){
                        cnt0--;
                    }
                    l++;
                }
            }
            ans = max(ans, r - l + 1);
            r++;
        }

        return ans - 1;
    }
};