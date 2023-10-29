class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();

        for(int bit = 0; bit < 32; bit++){
            int cnt = 0;
            for(int num : nums){
                if((num & (1 << bit)) != 0){
                    cnt++;
                }
            }
            if(cnt >= k){
                ans = ans | (1 << bit);
            }
        }

        return ans;
    }
};