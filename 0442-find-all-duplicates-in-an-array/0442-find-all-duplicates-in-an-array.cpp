class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        map<int, int> mp; //(num, cnt)
        int n = nums.size();

        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
        }

        vector<int> ans;
        for(auto it : mp){
            if(it.second == 2){
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};