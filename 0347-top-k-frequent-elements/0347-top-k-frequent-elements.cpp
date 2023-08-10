class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        int n = nums.size();

        for(int num : nums){
            mp[num]++;
        }

        vector<vector<int>> cnt(n + 1);
        
        for(auto it : mp){
            int ele = it.first;
            int count = it.second;

            cnt[count].push_back(ele);
        }

        vector<int> ans;

        for(int i = n; i >= 0; i--){
            
            vector<int> v = cnt[i];

            for(int i = 0; i < v.size(); i++){
                ans.push_back(v[i]);
                if(ans.size() == k){
                    return ans;
                }
            }
        }

        return ans;
    }
};