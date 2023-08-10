class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;

        for(char ch : s){
            mp[ch]++;
        }

        priority_queue<pair<int, char>> pq;

        for(auto it : mp){
            int cnt = it.second;
            char ele = it.first;

            pq.push({cnt, ele});
        }

        string ans = "";

        while(!pq.empty()){
            char ele = pq.top().second;
            int cnt = pq.top().first;
            pq.pop();

            for(int i = 0; i < cnt; i++){
                ans += ele;
            }
        }

        return ans;
    }
};