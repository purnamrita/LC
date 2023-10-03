class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mp;

        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
        }

        int ans = 0;

        for(auto it : mp){
            int no = it.second;
            ans += (no * (no - 1)) / 2;
        }

        return ans;
    }
};