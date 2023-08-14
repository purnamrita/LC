class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> temp;
        for(int num : nums){
            if(num != 0){
                temp.push_back(num);
            }
        }
        int nz = temp.size();
        for(int i = 0; i < nz; i++){
            nums[i] = temp[i];
        }
        for(int i = nz; i < nums.size(); i++){
            nums[i] = 0;
        }
    }
};