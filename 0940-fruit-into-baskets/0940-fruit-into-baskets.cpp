class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int ans = 0;
        int s = 0;
        int e = 0;
        unordered_map<int, int> mp;

        while(e < n){
            mp[fruits[e]]++;
            if(mp.size() > 2){
                while(mp.size() > 2){
                    mp[fruits[s]]--;
                    if(mp[fruits[s]] == 0){
                        mp.erase(fruits[s]);
                    }
                    s++;
                }
            }
            ans = max(ans, e - s + 1);
            e++;
        }

        return ans;
    }
};