class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // find longest consecutive subarray having atmost 2 distinct elements
        int ans = 0;
        unordered_map<int, int> mp;
        int start = 0;
        int end = 0;
        while(end < fruits.size()){
            mp[fruits[end]]++;
            if(mp.size() <= 2){
                ans = max(ans, end - start + 1);
            }
            else{
                while(mp.size() > 2){
                    mp[fruits[start]]--;
                    if(mp[fruits[start]] == 0){
                        mp.erase(fruits[start]);
                    }
                    start++;
                }
                ans = max(ans, end - start + 1);
            }
            end++;
        }
        return ans;
    }
};