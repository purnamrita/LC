class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        int ans = 0;
        int l = 0;
        int r = 0;
        unordered_set<char> s;

        while(r < str.length()){
            if(s.find(str[r]) == s.end()){
                s.insert(str[r]);
                ans = max(ans, r - l + 1);
                r++;
            }
            else{
                while(s.find(str[r]) != s.end()){
                    s.erase(str[l]);
                    l++;
                }
            }
        }

        return ans;
    }
};