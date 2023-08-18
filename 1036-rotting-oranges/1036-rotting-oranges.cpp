class Solution {
public:
    bool checkBounds(int x, int y, int rows, int cols){
        return (x >= 0 && x < rows && y >= 0 && y < cols);
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int time = 0;

        queue<pair<int, int>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }

        while(!q.empty()){
            int sz = q.size();
            int flag = 0;
            
            for(int i = 0; i < sz; i++){
                auto topIt = q.front();
                q.pop();
                int x = topIt.first;
                int y = topIt.second;

                for(int i = 0; i < 4; i++){
                    int newx = x + delRow[i];
                    int newy = y + delCol[i];
                    if(checkBounds(newx, newy, m, n) && grid[newx][newy] == 1 && !vis[newx][newy]){
                        q.push({newx, newy});
                        vis[newx][newy] = 1;
                        flag = 1;
                    }
                }
            }

            if(flag){
                time++;
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    return -1;
                }
            }
        }

        return time;

    }
};