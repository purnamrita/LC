//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void dfs(int row, int col, vector<vector<char>> grid, vector<vector<int>> &vis, int delRow[], int delCol[]){
	int n = grid.size();
	int m = grid[0].size();
	
	vis[row][col] = 1;
	for(int i = 0; i < 8; i++){
		int nrow = row + delRow[i];
		int ncol = col + delCol[i];
		if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && !vis[nrow][ncol] ){
			dfs(nrow, ncol, grid, vis, delRow, delCol);
}
}
}





int numIslands(vector<vector<char>> grid){
	int n = grid.size();
	int m = grid[0].size();
	
	int delRow[] = {-1, -1, -1, 0, 1, 1, 1, 0};
	int delCol[] = {-1, 0, 1, 1, 1, 0, -1, -1};

	
	int cnt = 0;
	vector<vector<int>> vis(n, vector<int>(m, 0));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(grid[i][j] == '1' && !vis[i][j]){
				dfs(i, j, grid, vis, delRow, delCol);
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