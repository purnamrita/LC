class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int l = 0;
        int r = 0;
        unordered_set<char> hashSet;

        while(r < s.length()){
            if(hashSet.find(s[r]) == hashSet.end()){
                ans = max(ans, r - l + 1);
                hashSet.insert(s[r]);
                r++;
            }
            else{
                while(hashSet.find(s[r]) != hashSet.end()){
                    hashSet.erase(s[l]);
                    l++;
                }
            }
        }

        return ans;
    }
};

