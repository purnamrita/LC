//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    bool isValid(int row, int col, int n, int m){
        return (row >= 0 && row < n && col >= 0 && col < m);
    }
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        
        if(source == destination){
            return 0;
        }
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> distance(n, vector<int>(m, INT_MAX));
        distance[source.first][source.second] = 0;
        
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {source.first, source.second}});
        vis[source.first][source.second] = 1;
        
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        
        while(!q.empty()){
            int row = q.front().second.first;
            int col = q.front().second.second;
            int dist = q.front().first;
            q.pop();
            
            for(int i = 0; i < 4; i++){
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                if(isValid(nrow, ncol, n, m) && grid[nrow][ncol] == 1){
                    if(dist + 1 < distance[nrow][ncol]){
                        distance[nrow][ncol] = dist + 1;
                        if(nrow == destination.first && ncol == destination.second){
                            return distance[nrow][ncol];
                        }
                        q.push({distance[nrow][ncol], {nrow, ncol}});
                    }
                }
            }
            
        }
        
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends