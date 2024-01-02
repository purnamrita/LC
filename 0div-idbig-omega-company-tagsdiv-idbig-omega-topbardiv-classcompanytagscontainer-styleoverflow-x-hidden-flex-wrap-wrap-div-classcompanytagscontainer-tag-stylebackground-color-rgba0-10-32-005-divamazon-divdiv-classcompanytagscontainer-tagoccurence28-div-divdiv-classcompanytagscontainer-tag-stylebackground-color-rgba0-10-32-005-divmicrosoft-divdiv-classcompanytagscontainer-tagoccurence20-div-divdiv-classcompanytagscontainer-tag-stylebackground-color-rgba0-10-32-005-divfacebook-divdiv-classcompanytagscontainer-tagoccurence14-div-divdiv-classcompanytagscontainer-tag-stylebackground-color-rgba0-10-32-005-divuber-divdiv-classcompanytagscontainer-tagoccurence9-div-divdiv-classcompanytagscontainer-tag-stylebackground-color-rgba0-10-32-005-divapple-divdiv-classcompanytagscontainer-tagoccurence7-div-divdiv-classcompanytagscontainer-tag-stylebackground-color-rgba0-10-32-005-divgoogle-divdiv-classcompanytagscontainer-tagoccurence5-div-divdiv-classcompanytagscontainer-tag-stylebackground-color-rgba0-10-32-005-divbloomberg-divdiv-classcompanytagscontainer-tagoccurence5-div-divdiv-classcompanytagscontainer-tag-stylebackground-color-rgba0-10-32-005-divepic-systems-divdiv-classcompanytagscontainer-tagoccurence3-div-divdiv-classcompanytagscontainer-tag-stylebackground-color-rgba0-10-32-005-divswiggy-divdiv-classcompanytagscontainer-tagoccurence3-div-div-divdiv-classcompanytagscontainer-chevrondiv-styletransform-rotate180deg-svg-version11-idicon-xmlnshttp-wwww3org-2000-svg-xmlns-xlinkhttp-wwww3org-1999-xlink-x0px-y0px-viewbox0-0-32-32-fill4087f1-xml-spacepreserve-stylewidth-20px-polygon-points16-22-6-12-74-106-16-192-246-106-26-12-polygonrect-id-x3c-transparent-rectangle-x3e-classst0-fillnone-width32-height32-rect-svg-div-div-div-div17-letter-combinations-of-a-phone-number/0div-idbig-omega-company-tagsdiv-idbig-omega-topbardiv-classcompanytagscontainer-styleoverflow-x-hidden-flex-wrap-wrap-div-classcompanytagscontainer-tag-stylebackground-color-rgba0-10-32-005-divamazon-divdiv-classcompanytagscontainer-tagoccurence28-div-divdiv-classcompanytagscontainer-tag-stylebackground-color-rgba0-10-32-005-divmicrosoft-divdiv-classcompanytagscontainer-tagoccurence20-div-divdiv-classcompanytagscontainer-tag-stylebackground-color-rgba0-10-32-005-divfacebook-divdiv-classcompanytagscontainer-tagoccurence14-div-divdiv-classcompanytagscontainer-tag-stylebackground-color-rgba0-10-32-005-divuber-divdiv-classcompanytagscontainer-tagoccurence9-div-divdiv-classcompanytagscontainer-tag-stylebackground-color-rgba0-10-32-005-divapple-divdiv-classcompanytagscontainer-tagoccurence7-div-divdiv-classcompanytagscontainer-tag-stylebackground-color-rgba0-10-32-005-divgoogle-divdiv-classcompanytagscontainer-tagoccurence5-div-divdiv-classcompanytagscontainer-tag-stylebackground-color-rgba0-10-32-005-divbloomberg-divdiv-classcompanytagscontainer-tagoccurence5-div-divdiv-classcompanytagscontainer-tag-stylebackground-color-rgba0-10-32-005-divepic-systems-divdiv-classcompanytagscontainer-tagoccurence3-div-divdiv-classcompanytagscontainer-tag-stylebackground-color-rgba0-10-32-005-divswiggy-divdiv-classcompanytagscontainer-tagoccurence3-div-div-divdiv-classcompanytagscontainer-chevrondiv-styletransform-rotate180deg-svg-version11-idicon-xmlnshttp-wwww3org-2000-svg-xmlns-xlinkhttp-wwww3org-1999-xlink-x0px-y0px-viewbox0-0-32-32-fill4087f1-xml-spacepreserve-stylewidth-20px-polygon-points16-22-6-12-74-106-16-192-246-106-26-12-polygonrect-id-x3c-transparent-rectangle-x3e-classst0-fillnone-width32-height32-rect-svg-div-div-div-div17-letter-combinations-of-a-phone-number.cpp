class Solution {
public:
    
    vector<string> helper(int idx, string &digits, map<int, string> &mp){
        if(idx == digits.size()){
            return {""};
        }
        vector<string> temp = helper(idx + 1, digits, mp);
        vector<string> ans;
        
        for(auto str : temp){
            for(auto x : mp[digits[idx] - '0']){
                ans.push_back(x + str);
            }
        }
        
        return ans;
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0){
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