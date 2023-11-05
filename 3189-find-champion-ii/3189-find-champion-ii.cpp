class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        unordered_set<int> s;
        for(int i = 0; i < n; i++){
            s.insert(i);
        }

        for(auto it : edges){
            int v = it[1];
            s.erase(v);
        }

        if(s.size() != 1){
            return -1;
        }
        for(auto it : s){
            return it;
        }
        return -1;
    }
};