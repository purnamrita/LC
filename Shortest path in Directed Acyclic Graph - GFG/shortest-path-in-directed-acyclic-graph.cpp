//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  private:
    void topoSort(int src, vector<pair<int, int>> adj[], stack<int> &st, vector<int> &vis){
        vis[src] = 1;
        
        for(auto it : adj[src]){
            if(!vis[it.first]){
                topoSort(it.first, adj, st, vis);
            }
        }
        
        st.push(src);
        
    }
    
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        
        vector<pair<int, int>> adj[N];
        
        for(int i = 0; i < M; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            adj[u].push_back({v, wt});
        }
        
        vector<int> vis(N);
        stack<int> st;
        
        for(int i = 0; i < N; i++){
            if(!vis[i]){
                topoSort(i, adj, st, vis);
            }
        }
        
        vector<int> dist(N, INT_MAX);
        dist[0] = 0;
        
        while(!st.empty()){
            int node = st.top();
            st.pop();
            int curr_dist = dist[node];
            
            for(auto it : adj[node]){
                int neigh = it.first;
                int wt = it.second;
                
                if(curr_dist != INT_MAX && curr_dist + wt < dist[neigh]){
                    dist[neigh] = curr_dist + wt;
                }
            }
        }
        
        for(int i = 0; i < N; i++){
            if(dist[i] == INT_MAX){
                dist[i] = -1;
            }
        }
        
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
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