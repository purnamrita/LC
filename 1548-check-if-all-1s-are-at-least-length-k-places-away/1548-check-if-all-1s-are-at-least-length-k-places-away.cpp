class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        int prev = 0;

        while(prev < n && nums[prev] != 1){
            prev++;
        }

        for(int curr = prev + 1; curr < n; curr++){
            if(nums[curr] == 1){
                if(curr - prev - 1 >= k){
                    prev = curr;
                }
                else{
                    return false;
                }
            }
        }

        return true;
    }
};