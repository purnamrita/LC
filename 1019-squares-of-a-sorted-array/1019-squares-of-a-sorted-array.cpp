class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);        
        int idx = n - 1;

        int low = 0;
        int high = n - 1;

        while(low <= high){
            if(abs(nums[low]) <= abs(nums[high])){
                ans[idx] = nums[high] * nums[high];
                high--;
            }
            else{
                ans[idx] = nums[low] * nums[low];
                low++;
            }
            idx--;
        }

        return ans;
    }
};