class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int curr = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] == 1){
                curr++;
            }
            else{
                ans = max(ans, curr);
                curr = 0;
            }
        }
        ans = max(ans, curr);

        return ans;
    }
};