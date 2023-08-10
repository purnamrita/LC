class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            int findNum = target - nums[i];
            if(mp.find(findNum) != mp.end()){
                return {i, mp[findNum]};
            }
            mp.insert({nums[i], i});
        }

        return {-1, -1};
    }
};