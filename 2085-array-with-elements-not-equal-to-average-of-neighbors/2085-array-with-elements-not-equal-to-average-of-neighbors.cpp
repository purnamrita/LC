class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        sort(nums.begin(), nums.end());
        
        int l = 0;
        int r = n - 1;

        while(ans.size() < n){
            ans.push_back(nums[l]);
            l++;

            if(l < r){
                ans.push_back(nums[r]);
                r--;
            }
        }

        return ans;
    }
};