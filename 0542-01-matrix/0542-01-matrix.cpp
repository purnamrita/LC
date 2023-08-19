class Solution {
public:
    bool checkValidBounds(int x, int y, int rows, int cols){
        return (x >= 0 && x < rows && y >= 0 && y < cols);
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};


        vector<vector<int>> ans(n, vector<int>(m, 0));
        vector<vector<int>> vis(n, vector<int>(m, 0));

        queue<pair<pair<int, int>, int>> q;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    vis[i][j] = 1;
                    q.push({{i, j}, 0});
                }
            }
        }

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int row = it.first.first;
            int col = it.first.second;
            int dist = it.second;
            ans[row][col] = dist;

            for(int i = 0; i < 4; i++){
                int newr = row + delRow[i];
                int newc = col + delCol[i];

                if(checkValidBounds(newr, newc, n, m) && !vis[newr][newc] && mat[newr][newc] == 1){
                    q.push({{newr, newc}, dist + 1});
                    vis[newr][newc] = 1;
                }
            }
        }

        return ans;
    }
};