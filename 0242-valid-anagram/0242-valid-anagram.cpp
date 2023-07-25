class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        map<char, int> mp;
        int n = s.length();

        for(int i = 0; i < n; i++){
            mp[s[i]]++;
            mp[t[i]]--;
        }

        for(auto it : mp){
            if(it.second != 0){
                return false;
            }
        }

        return true;
    }
};