class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++){
            mp[nums[i]]++;  //(ele, cnt)
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minh;
        
        for(auto it : mp){
            int ele = it.first;
            int cnt = it.second;
            minh.push({cnt, ele});

            if(minh.size() > k){
                minh.pop();
            }
        }

        vector<int> ans;
        while(!minh.empty()){
            int ele = minh.top().second;
            ans.push_back(ele);
            minh.pop();
        }
        return ans;
    }
};