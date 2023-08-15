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
    void helper(TreeNode* root, int targetSum, unordered_map<long long, int> &mp, long long sum, int &cnt){
        if(root == NULL){
            return;
        }
        sum += root -> val;
        if(mp.find(sum - targetSum) != mp.end()){
            cnt += mp[sum - targetSum];
        }
        mp[sum]++;
        helper(root -> left, targetSum, mp, sum, cnt);
        helper(root -> right, targetSum, mp, sum, cnt);
        mp[sum]--;
        sum -= root -> val;
        if(mp[sum] == 0){
            mp.erase(sum);
        }
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> mp;
        mp[0]++;
        int cnt = 0;
        helper(root, targetSum, mp, 0, cnt);
        return cnt;
    }
};