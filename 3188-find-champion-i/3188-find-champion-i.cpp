class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n = grid.size();

        unordered_set<int> s;
        for(int i = 0; i < n; i++){
            s.insert(i);
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i != j){
                    if(grid[i][j] == 1){
                        s.erase(j);
                    }
                    else{
                        s.erase(i);
                    }
                }
            }
        }

        for(auto it : s){
            return it;
        }
        return -1;
    }
};