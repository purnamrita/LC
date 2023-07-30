//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void bfs(int node, vector<int> adjL[], vector<int> &vis){
        queue<int> q;
        q.push(node);
        vis[node] = 1;
        
        while(!q.empty()){
            int ele = q.front();
            q.pop();
            
            for(auto it : adjL[ele]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
    }
    
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int> adjL[V];
        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                if(adj[i][j] == 1 && i != j){
                    adjL[i].push_back(j);
                }
            }
        }
        
        vector<int> vis(V);
        int cnt = 0;
        
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                cnt++;
                bfs(i, adjL, vis);
            }
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends