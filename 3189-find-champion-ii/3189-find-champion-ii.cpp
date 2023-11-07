class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        unordered_set<int> s;
        for(int ele = 0; ele < n; ele++){
            s.insert(ele);
        }

        for(auto it : edges){
            s.erase(it[1]);
        }

        if(s.size() != 1){
            return -1;
        }
        for(auto ele : s){
            return ele;
        }
        return -1;
    }
};