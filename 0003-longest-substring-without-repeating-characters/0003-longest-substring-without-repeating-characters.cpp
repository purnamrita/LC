class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;

        int maxi = INT_MIN;
        int curr = 0;

        for(int i = 0; i < s.length(); i++){
            if(st.find(s[i]) == st.end()){
                curr++;
                st.insert(s[i]);
            }
            else{
                maxi = max(maxi, curr);
                while(st.find(s[i]) != st.end()){
                    st.erase(s[i - curr]);
                    curr--;
                }
                st.insert(s[i]);
                curr++;
            }
        }
        maxi = max(maxi, curr);
        return maxi;
    }
};

