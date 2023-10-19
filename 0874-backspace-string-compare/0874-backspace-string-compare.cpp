class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st;

        for(int i = 0; i < s.length(); i++){
            if(s[i] != '#'){
                st.push(s[i]);
            }
            else{
                if(st.empty() == false){
                    st.pop();
                }
            }
        }
        string sr;
        while(!st.empty()){
            sr += st.top();
            st.pop();
        }

        for(int i = 0; i < t.length(); i++){
            if(t[i] != '#'){
                st.push(t[i]);
            }
            else{
                if(st.empty() == false){
                    st.pop();
                }
            }
        }
        string str;
        while(!st.empty()){
            str += st.top();
            st.pop();
        }

        if(sr.length() != str.length()){
            return false;
        }
        for(int i = 0; i < sr.length(); i++){
            if(sr[i] != str[i]){
                return false;
            }
        }
        return true;
    }
};