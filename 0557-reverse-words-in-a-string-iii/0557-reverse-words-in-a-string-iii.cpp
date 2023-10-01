class Solution {
public:
    string rev(string w){
        int l = 0;
        int r = w.length() - 1;

        while(l < r){
            char temp = w[l];
            w[l] = w[r];
            w[r] = temp;
            l++;
            r--;
        }

        return w;
    }

    string reverseWords(string s) {
        string ans = "";
        string word = "";

        int i = 0;
        while(i < s.length()){
            if(s[i] != ' '){
                word += s[i];
            }
            else{
                word = rev(word);
                ans += word;
                ans += " ";
                word = "";
            }
            i++;
        }

        word = rev(word);
        ans += word;

        return ans;
    }
};