class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n < 2){
            return false;
        }
        unordered_map<int, int> mp;
        mp[0] = -1;

        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            int rem = sum % k;
            if(mp.find(rem) != mp.end() && i - mp[rem] > 1){
                return true;
            }
            if(mp.find(rem) == mp.end()){
                mp[rem] = i;
            }
        }

        return false;

    }
};