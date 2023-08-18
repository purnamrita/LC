class Solution {
public:
    bool checkBounds(int x, int y, int rows, int cols){
        return (x >= 0 && x < rows && y >= 0 && y < cols);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int ori = image[sr][sc];
        vector<vector<int>> ans = image;

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        vector<vector<int>> vis(m, vector<int>(n, 0));

        queue<pair<int, int>> q;
        q.push({sr, sc});
        vis[sr][sc] = 1;
        ans[sr][sc] = color;

        while(!q.empty()){
            auto node = q.front();
            q.pop();
            int x = node.first;
            int y = node.second;

            for(int i = 0; i < 4; i++){
                int newr = x + delRow[i];
                int newc = y + delCol[i];
                if(checkBounds(newr, newc, m, n) && !vis[newr][newc] && ans[newr][newc] == ori){
                    ans[newr][newc] = color;
                    q.push({newr, newc});
                    vis[newr][newc] = 1;
                }
            }
        }

        return ans;
    }
};