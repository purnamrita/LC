//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>> &vis){
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        int rows = grid.size();
        int cols = grid[0].size();
        
        while(!q.empty()){
            int currRow = q.front().first;
            int currCol = q.front().second;
            q.pop();
            
            for(int delRow = -1; delRow <= 1; delRow++){
                for(int delCol = -1; delCol <= 1; delCol++){
                    int nRow = currRow + delRow;
                    int nCol = currCol + delCol;
                    if(nRow >= 0 && nRow < rows && nCol >= 0 && nCol < cols &&
                    vis[nRow][nCol] == 0 && grid[nRow][nCol] == '1'){
                        vis[nRow][nCol] = 1;
                        q.push({nRow, nCol});
                    }
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<vector<int>> vis(rows, vector<int>(cols, 0));
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == '1' && vis[i][j] == 0){
                    bfs(i, j, grid, vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends