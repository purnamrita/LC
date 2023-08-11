class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int i = 0; i < 32; i++){
            int cnt1 = 0;
            int cnt0 = 0;
            for(int j = 0; j < n; j++){
                if(nums[j] & (1 << i)){
                    cnt1++;
                }
                else{
                    cnt0++;
                }
            }

            if(cnt1 % 3){
                ans = ans | (1<<i);
            }
            else{
                ans = ans | (0 <<i);
            }
        }
        return ans;
    }
};