class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> mp;

        for(auto str : strs){
            vector<int> cnt(26);
            for(auto ch : str){
                cnt[ch - 'a']++;
            }
            mp[cnt].push_back(str);
        }

        vector<vector<string>> ans;

        for(auto it : mp){
            ans.push_back(it.second);
        }

        return ans;
    }
};