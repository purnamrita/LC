class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int jumps = 0;
        int farthest = l;

        while(r < n - 1){
            for(int i = l; i <= r; i++){
                if(nums[i] + i > farthest){
                    farthest = nums[i] + i;
                }
            }
            l = r + 1;
            r = farthest;
            jumps++;
        }

        return jumps;
    }
};