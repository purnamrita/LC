class Solution {
public:
    int findNoOfOnes(vector<int> v){
        if(v[0] == 0){
            return 0;
        }
        int ans;
        int l = 0;
        int r = v.size() - 1;

        while(l <= r){
            int m = l + (r - l) / 2;
            if(v[m] == 0){
                r = m - 1;
            }
            else{
                ans = m;
                l = m + 1;
            }
        }
        return ans + 1;
    }

    static bool comp(pair<int, int> p1, pair<int, int> p2){
        if(p1.first < p2.first){
            return true;
        }
        else if(p1.first == p2.first){
            return (p1.second < p2.second);
        }
        return false;
    }

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> vStore; // (no of soldiers, row no)

        for(int i = 0; i < mat.size(); i++){
            vStore.push_back({findNoOfOnes(mat[i]), i});
        }
        sort(vStore.begin(), vStore.end(), comp);

        vector<int> ans;
        for(auto it : vStore){
            if(k > 0){
                ans.push_back(it.second);
                k--;
            }
            else{
                break;
            }
        }
        return ans;
    }
};