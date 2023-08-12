class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        unordered_set<char> st;
        int ans = 0;
        int curr = 0;
        int start = 0;
        int end = 0;

        while(end < str.size()){
            if(st.find(str[end]) == st.end()){
                st.insert(str[end]);
                ans = max(ans, end - start + 1);
                end++;
            }
            else{
                while(st.find(str[end]) != st.end()){
                    st.erase(str[start]);
                    start++;
                }
            }
        }

        return ans;
    }
};