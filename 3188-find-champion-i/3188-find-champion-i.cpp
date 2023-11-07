class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_set<int> s;
        for(int ele = 0; ele < n; ele++){
            s.insert(ele);
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    s.erase(j);
                }
            }
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