class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int diff = INT_MAX;
        int n = nums.size();

        int i = 0;
        int j = k - 1;

        while(j < n){
            diff = min(diff, nums[j] - nums[i]);
            i++;
            j++;
        }

        return diff;
    }
};