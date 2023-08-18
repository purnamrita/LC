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
    void preorder(TreeNode* root, vector<int> &v){
        if(root == NULL){
            return;
        }
        preorder(root -> left, v);
        v.push_back(root -> val);
        preorder(root -> right, v);
    }
    vector<int> mergeLists(vector<int> v1, vector<int> v2){
        int n1 = v1.size();
        int n2 = v2.size();
        vector<int> v;

        int i = 0;
        int j = 0;

        while(i < n1 && j < n2){
            if(v1[i] <= v2[j]){
                v.push_back(v1[i]);
                i++;
            }
            else{
                v.push_back(v2[j]);
                j++;
            }
        }
        while(i < n1){
            v.push_back(v1[i]);
            i++;
        }
        while(j < n2){
            v.push_back(v2[j]);
            j++;
        }

        return v;
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1;
        vector<int> v2;
        preorder(root1, v1);
        preorder(root2, v2);
        return mergeLists(v1, v2);
    }
};