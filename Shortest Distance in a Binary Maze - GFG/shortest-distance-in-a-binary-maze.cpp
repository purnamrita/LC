//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        
        if(destination.first == source.first && destination.second == source.second){
            return 0;
        }
        
        int n = grid.size();
        int m = grid[0].size();
        
        int delRow[] = {0, 1, 0, -1};
        int delCol[] = {1, 0, -1, 0};
         
        queue<pair<int, pair<int, int>>> q;
        
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[source.first][source.second] = 0;
        
        q.push({0, {source.first, source.second}});
        
        while(!q.empty()){
            int dis = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();
            
            for(int i = 0; i < 4; i++){
                int newx = x + delRow[i];
                int newy = y + delCol[i];
                
                if(newx >= 0 && newx < n && newy >= 0 && newy < m && grid[newx][newy] == 1 && dis + 1 < dist[newx][newy]){
                    dist[newx][newy] = dis + 1;
                    if(newx == destination.first && newy == destination.second){
                        return dis + 1;
                    }
                    q.push({dis + 1, {newx, newy}});
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