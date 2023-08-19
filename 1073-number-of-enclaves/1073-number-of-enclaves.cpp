class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, int delRow[], int delCol[]){
        int m = grid.size();
        int n = grid[0].size();

        vis[row][col] = 1;

        for(int i = 0; i < 4; i++){
            int newr = row + delRow[i];
            int newc = col + delCol[i];

            if(newr >= 0 && newr < m && newc >= 0 && newc < n && grid[newr][newc] == 1 && !vis[newr][newc]){
                dfs(newr, newc, grid, vis, delRow, delCol);
            }
        }

    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        vector<vector<int>> vis(m, vector<int>(n, 0));

        //cols
        for(int i = 0; i < m; i++){
            if(grid[i][0] == 1 && !vis[i][0]){
                dfs(i, 0, grid, vis, delRow, delCol);
            }
            if(grid[i][n - 1] == 1 && !vis[i][n - 1]){
                dfs(i, n - 1, grid, vis, delRow, delCol);
            }
        }

        //rows
        for(int j = 0; j < n; j++){
            if(grid[0][j] == 1 && !vis[0][j]){
                dfs(0, j, grid, vis, delRow, delCol);
            }
            if(grid[m - 1][j] == 1 && !vis[m - 1][j]){
                dfs(m - 1, j, grid, vis, delRow, delCol);
            }
        }

        int cnt = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(vis[i][j] == 0 && grid[i][j] == 1){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};