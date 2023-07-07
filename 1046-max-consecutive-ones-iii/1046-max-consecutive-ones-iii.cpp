class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt0 = 0;
        int ans = 0;
        int l = 0;
        int r = 0;

        while(r < n){
            if(nums[r] == 0){
                if(cnt0 < k){
                    cnt0++;
                }
                else{
                    while(cnt0 >= k){
                        if(nums[l] == 0){
                            cnt0--;
                        }
                        l++;
                    }
                    cnt0 += 1;
                }
            }
            ans = max(ans, r - l + 1);
            r++;
        }

        return ans;
    }
};