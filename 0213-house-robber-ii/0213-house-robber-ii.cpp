class Solution {
public:
    int rob_helper(vector<int> &nums){
        int n = nums.size();
        int prev1 = 0;
        int prev = nums[0];
        int curr;

        for(int i = 1; i < n; i++){
            int pick = nums[i] + prev1;
            int not_pick = prev;
            curr = max(pick, not_pick);
            prev1 = prev;
            prev = curr;
        }
        return prev;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        vector<int> temp1;
        vector<int> temp2;

        for(int i = 0; i < n; i++){
            if(i != 0){
                temp1.push_back(nums[i]);
            }
            if(i != n - 1){
                temp2.push_back(nums[i]);
            }
        }

        return max(rob_helper(temp1), rob_helper(temp2));
    }
};