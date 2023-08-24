//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<pair<int, int>> adj[n + 1];
        
        for(int i = 0; i < m; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int dist = edges[i][2];
            adj[u].push_back({v, dist});
            adj[v].push_back({u, dist});
        }
        
        vector<int> dist(n + 1, INT_MAX);
        vector<int> parent(n + 1);
        for(int i = 1; i <= n; i++){
            parent[i] = i;
        }
        
        dist[1] = 0;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 1});
        
        while(!pq.empty()){
            auto itr = pq.top();
            pq.pop();
            int distance = itr.first;
            int node = itr.second;
            
            for(auto it : adj[node]){
                int adjNode = it.first;
                int edgeWt = it.second;
                
                if(distance + edgeWt < dist[adjNode]){
                    dist[adjNode] = distance + edgeWt;
                    pq.push({dist[adjNode], adjNode});
                    parent[adjNode] = node;
                }
            }
        }
        
        if(dist[n] == INT_MAX){
            return {-1};
        }
        vector<int> path;
        path.push_back(n);
        int currNode = n;
        
        while(parent[currNode] != currNode){
            path.push_back(parent[currNode]);
            currNode = parent[currNode];
        }
        reverse(path.begin(), path.end());
        return path;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends