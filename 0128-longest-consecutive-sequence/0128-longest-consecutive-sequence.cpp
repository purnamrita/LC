class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;

        int n = nums.size();

        if(n == 0){
            return 0;
        }

        int cnt = 1;
        int prev = nums[0];
        for(int i = 1; i < n; i++){
            if(nums[i] - nums[i - 1] == 1){
                cnt++;
                prev = nums[i];
            }
            else if(nums[i] == nums[i - 1]){
                continue;
            }
            else{
                ans = max(ans, cnt);
                cnt = 1;
                prev = nums[i];
            }
        }
        ans = max(ans, cnt);

        return ans;
    }
};