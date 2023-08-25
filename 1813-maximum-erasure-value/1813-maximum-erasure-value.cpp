class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        set<int> s;

        int l = 0;
        int r = 0;
        int sum = 0;

        while(r < n){
            while(s.find(nums[r]) != s.end()){
                s.erase(nums[l]);
                sum -= nums[l];
                l++;
            }
            sum += nums[r];
            s.insert(nums[r]);
            ans = max(ans, sum);
            r++;
        }

        return ans;
    }
};