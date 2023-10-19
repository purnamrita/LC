class Solution {
public:
    string stringRemove(string str){
        string ans;
        for(char ch : str){
            if(ch == '#'){
                if(!ans.empty()){
                    ans.pop_back();
                }
            }
            else{
                ans += ch;
            }
        }
        return ans;
    }
    bool backspaceCompare(string s, string t) {
        return stringRemove(s) == stringRemove(t);
    }
};