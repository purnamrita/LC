/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void pathSumHelper(TreeNode* root, int targetSum, long long &sum, unordered_map<long long, int> &mp, int &ans){
        if(root == NULL){
            return;
        }
        sum += root -> val;
        if(mp.find(sum - targetSum) != mp.end()){
            ans += mp[sum - targetSum];
        }
        mp[sum]++;
        pathSumHelper(root -> left, targetSum, sum, mp, ans);
        pathSumHelper(root -> right, targetSum, sum, mp, ans);
        mp[sum]--;
        if(mp[sum] == 0){
            mp.erase(sum);
        }
        sum -= root -> val;
    }
    int pathSum(TreeNode* root, int targetSum) {
        long long sum = 0;
        unordered_map<long long, int> mp;
        mp[0] = 1;
        int ans = 0;
        pathSumHelper(root, targetSum, sum, mp, ans);
        return ans;
    }
};