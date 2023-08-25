class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;

        int cnt = 0;
        int prev = nums[0];

        for(int i = 0; i < n; i++){
            if(nums[i] == prev){
                cnt++;
            }
            else{
                cnt = 1;
                prev = nums[i];
            }
            if(cnt <= 2){
                nums[j] = nums[i];
                j++;
            }
        }

        return j;
    }
};