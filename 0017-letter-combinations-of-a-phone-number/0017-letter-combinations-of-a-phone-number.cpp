class Solution {
public:
    vector<string> helper(int i, string &digits, map<int, string> &mp){
        int n = digits.size();
        if(i == n){
            return {""};
        }
        vector<string> v = helper(i + 1, digits, mp);
        vector<string> ans;

        for(char ch : mp[digits[i] - '0']){
            for(auto it : v){
                ans.push_back(ch + it);
            }
        }
        return ans;
    }

    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0){
            return {};
        }
        map<int, string> mp;
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        return helper(0, digits, mp);
    }
};