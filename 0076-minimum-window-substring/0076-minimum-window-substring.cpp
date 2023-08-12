class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> mp;

        for(char ch : t){
            mp[ch]++;
        }

        int counter = t.size();

        int left = 0;
        int right = 0;

        int minStart = 0;
        int minLength = INT_MAX;

        while(right < s.length()){
            if(mp[s[right]] > 0){
                counter--;
            }
            mp[s[right]]--;
            right++;

            while(counter == 0){
                if(right - left < minLength){
                    minLength = right - left;
                    minStart = left;
                }

                mp[s[left]]++;
                if(mp[s[left]] > 0){
                    counter++;
                }
                left++;
            }
        }

        if(minLength != INT_MAX){
            return s.substr(minStart, minLength);
        }
        return "";
    }
};