class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string> > mp;

        int n = strs.size();

        for(int i = 0; i < n; i++){
            string s = strs[i];
            vector<int> key(26);

            for(char ch : s){
                key[ch - 'a']++;
            }

            mp[key].push_back(s);
        }

        vector<vector<string>> ans;

        for(auto it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};