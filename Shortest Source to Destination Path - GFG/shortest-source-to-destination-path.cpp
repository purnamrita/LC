//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        vector<vector<int>> vis(N, vector<int>(M, 0));
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        queue<pair<int, int>> q;
        q.push({0, 0});
        vis[0][0] = 1;
        
        int steps = 0;
        
        while(!q.empty()){
            int size = q.size();
            
            while(size--){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                
                if(row == X && col == Y){
                    return steps;
                }
                for(int i = 0; i < 4; i++){
                    int nrow = row + delRow[i];
                    int ncol = col + delCol[i];
                    
                    if(nrow >= 0 && nrow < N && ncol >= 0 && ncol < M && A[nrow][ncol] == 1 && !vis[nrow][ncol]){
                        q.push({nrow, ncol});
                        vis[nrow][ncol] = 1;
                    }
                }
            }
            steps++;
        }
        
        return -1;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends