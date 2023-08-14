class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, queue<pair<int, int>> &q, int delRow[], int delCol[]){
        int n = grid.size();
        vis[row][col] = 1;
        q.push({row, col});

        for(int i = 0; i < 4; i++){
            int newr = row + delRow[i];
            int newc = col + delCol[i];

            if(newr >= 0 && newr < n && newc >= 0 && newc < n && grid[newr][newc] == 1 && vis[newr][newc] == 0){
                dfs(newr, newc, grid, vis, q, delRow, delCol);
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> vis(n, vector<int>(n, 0));
        queue<pair<int, int>> q;

        int delRow[] = {1, 0, -1, 0};
        int delCol[] = {0, 1, 0, -1};
        bool flag = false;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    dfs(i, j, grid, vis, q, delRow, delCol);
                    flag = true;
                    break;
                }
            }
            if(flag){
                break;
            }
        }

        int steps = 0;

        while(!q.empty()){
            int sz = q.size();

            for(int i = 0; i < sz; i++){
                auto it = q.front();
                q.pop();
                int row = it.first;
                int col = it.second;

                for(int i = 0; i < 4; i++){
                    int nrow = row + delRow[i];
                    int ncol = col + delCol[i];

                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && !vis[nrow][ncol]){
                        if(grid[nrow][ncol] == 1){
                            return steps;
                        }
                        q.push({nrow, ncol});
                        vis[nrow][ncol] = 1;
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};