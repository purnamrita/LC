class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int l = k;
        int r = k;
        int left, right;
        int ans = nums[k];
        int mini = nums[k];

        while(l > 0 || r < n){
            left = (l - 1 >= 0) ? nums[l - 1] : 0;
            right = (r + 1 < n) ? nums[r + 1] : 0;

            if(left > right){
                mini = min(mini, left);
                l--;
            }
            else{
                mini = min(mini, right);
                r++;
            }
            ans = max(ans, mini * (r - l + 1));
        }

        return ans;
    }
};