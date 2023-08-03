class Solution {
public:
    void helper(int i, vector<int> &subset, vector<vector<int>> &ans, int n, int k){
        if(k == 0){
            ans.push_back(subset);
            return;
        }
        if(i > n){
            return;
        }
        int req = k - subset.size();
        int left = n - i + 1;

        if(left < req){
            return;
        }
        
        //take
        subset.push_back(i);
        helper(i + 1, subset, ans, n, k - 1);
        //not take
        subset.pop_back();
        helper(i + 1, subset, ans, n, k);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> subset;
        helper(1, subset, ans, n, k);
        return ans;
    }
};