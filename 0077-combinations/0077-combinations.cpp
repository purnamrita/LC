class Solution {
public:
    void helper(int i, int n, int k, vector<int> &subset, vector<vector<int>> &ans){
        if(k == 0){
            ans.push_back(subset);
            return;
        }
        if(i > n){
            return;
        }

        //take
        subset.push_back(i);
        helper(i + 1, n, k - 1, subset, ans);

        //not take
        subset.pop_back();
        helper(i + 1, n, k, subset, ans);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> subset;
        helper(1, n, k, subset, ans);
        return ans;
    }
};