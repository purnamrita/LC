class Solution {
public:
    bool isValid(int i, int j, int m, int n){
        if(i < 0 || j < 0 || i >= m || j >= n){
            return false;
        }
        return true;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1));
        queue<pair<int, int>> q;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            if(ans[i][j] != -1){
                if(isValid(i + 1, j, m, n) && ans[i + 1][j] == -1){
                    ans[i + 1][j] = ans[i][j] + 1;
                    q.push({i + 1, j});
                }
                if(isValid(i - 1, j, m, n) && ans[i - 1][j] == -1){
                    ans[i - 1][j] = ans[i][j] + 1;
                    q.push({i - 1, j});
                }
                if(isValid(i, j + 1, m, n) && ans[i][j + 1] == -1){
                    ans[i][j + 1] = ans[i][j] + 1;
                    q.push({i, j + 1});
                }
                if(isValid(i, j - 1, m, n) && ans[i][j - 1] == -1){
                    ans[i][j - 1] = ans[i][j] + 1;
                    q.push({i, j - 1});
                }
            }
            q.pop();
        }

        return ans;


    }
};