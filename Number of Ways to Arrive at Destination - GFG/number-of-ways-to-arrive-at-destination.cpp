//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        vector<vector<long long>> adj[n];
        
        for(auto it : roads){
            int u = it[0];
            int v = it[1];
            int tme = it[2];
            
            adj[u].push_back({v, tme});
            adj[v].push_back({u, tme});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<long long> dist(n, LONG_MAX);
        vector<int> ways(n, 0);
        ways[0] = 1;
        dist[0] = 0;
        int mod = 1e9 + 7;
        pq.push({0, 0});
        
        while(!pq.empty()){
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it : adj[node]){
                int adjNode = it[0];
                long long adjTm = it[1];
                
                if(dis + adjTm < dist[adjNode]){
                    dist[adjNode] = dis + adjTm;
                    ways[adjNode] = ways[node];
                    pq.push({dis + adjTm, adjNode});
                }
                else if(dis + adjTm == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        
        return ways[n - 1] % mod;
        
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends