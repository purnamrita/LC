class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1){
            return -1;
        }
        if(n == 1){
            return 1;
        }
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        dist[0][0] = 0;

        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0, 0}});

        int delRow[] = {0, -1, -1, -1, 0, 1, 1, 1};
        int delCol[] = {-1, -1, 0, 1, 1, 1, 0, -1};

        while(!q.empty()){
            auto it = q.front();
            int dis = it.first;
            int row = it.second.first;
            int col = it.second.second;
            q.pop();

            for(int i = 0; i < 8; i++){
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 0 && dis + 1 < dist[nrow][ncol]){
                    dist[nrow][ncol] = dis + 1;
                    q.push({dis + 1, {nrow, ncol}});
                }
            }

        }

        if(dist[n - 1][n - 1] == INT_MAX){
            return -1;
        }

        return dist[n - 1][n - 1];
    }
};