class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        for(char ch : t){
            mp[ch]++;
        }
        int count = t.size();
        int left = 0;
        int right = 0;

        int minStart = 0;
        int minLength = INT_MAX;

        while(right < s.size()){
            if(mp[s[right]] > 0){
                count--;
            }
            mp[s[right]]--;
            right++;

            while(count == 0){
                if(right - left < minLength){
                    minLength = right - left;
                    minStart = left;
                }
                mp[s[left]]++;
                if(mp[s[left]] > 0){
                    count++;
                }
                left++;
            }
        }

        if(minLength == INT_MAX){
            return "";
        }
        return s.substr(minStart, minLength);
         
    }
};