class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size()){
            return false;
        }
        vector<int> s1hash(26);
        vector<int> s2hash(26);

        for(char ch : s1){
            s1hash[ch - 'a']++;
        }

        int len = s1.size();

        for(int i = 0; i < len; i++){
            s2hash[s2[i] - 'a']++;
        }
        if(s1hash == s2hash){
            return true;
        }
        for(int i = len; i < s2.size(); i++){
            s2hash[s2[i] - 'a']++;
            s2hash[s2[i - len] - 'a']--;
            if(s1hash == s2hash){
                return true;
            }
        }
        return false;
    }
};