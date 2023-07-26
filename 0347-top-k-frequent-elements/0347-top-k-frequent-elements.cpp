class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;

        for(auto num : nums){
            mp[num]++;
        }

        vector<pair<int, int>> cnt;
        for(auto it : mp){
            cnt.push_back({it.second, it.first});
        }
        sort(cnt.begin(), cnt.end());

        vector<int> ans;
        int n = mp.size();
        for(int i = 0; i < k; i++){
            ans.push_back(cnt[n - i - 1].second);
        }

        return ans;
    }
};