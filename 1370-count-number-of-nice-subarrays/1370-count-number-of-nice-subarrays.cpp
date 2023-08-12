class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        int ans = 0;
        int odd = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] % 2){
                odd++;
            }
            if(odd == k){
                ans++;
            }
            if(mp.find(odd - k) != mp.end()){
                ans += mp[odd - k];
            }
            mp[odd]++;
        }
        return ans;
    }
};