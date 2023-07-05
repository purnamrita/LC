class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> mp; //(sum, cnt)
        mp[0] = 1;
        int n = nums.size();
        int sum = 0;
        int ans = 0;

        for(int i = 0; i < n; i++){
            sum += nums[i];
            if(mp.find(sum - k) != mp.end()){
                ans += mp[sum - k];
            }
            mp[sum]++;
        }

        return ans;
    }
};