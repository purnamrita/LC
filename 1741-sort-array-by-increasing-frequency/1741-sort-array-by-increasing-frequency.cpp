class Solution {
public:
    static bool cmp(vector<int> v1, vector<int> v2){
        if(v1[0] < v2[0]){
            return true;
        }
        if(v1[0] == v2[0]){
            return (v1[1] > v2[1]);
        }
        return false;
    }
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;

        for(int num : nums){
            mp[num]++;
        }

        vector<vector<int>> freq;

        for(auto it : mp){
            freq.push_back({it.second, it.first});
        }

        sort(freq.begin(), freq.end(), cmp);

        vector<int> ans;

        for(int i = 0; i < freq.size(); i++){
            int ele = freq[i][1];
            int cnt = freq[i][0];

            for(int i = 0; i < cnt; i++){
                ans.push_back(ele);
            }
        }

        return ans;
    }
};