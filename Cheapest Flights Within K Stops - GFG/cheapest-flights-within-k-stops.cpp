//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {

        vector<vector<int>> adj[n];
        
        for(int i = 0; i < flights.size(); i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int cost = flights[i][2];
            
            adj[u].push_back({v, cost});
        }
        
        queue<pair<int, pair<int, int>>> q; // (stops, node, dist)
        vector<int> flightCost(n, INT_MAX);
        flightCost[src] = 0;
        q.push({0, {src, 0}});
        
        while(!q.empty()){
            auto it = q.front();
            int stops = it.first;
            int node = it.second.first;
            int price = it.second.second;
            q.pop();
            
            if(stops > K){
                continue;
            }
            
            for(auto it : adj[node]){
                int adjNode = it[0];
                int edgePr = it[1];
                
                if(price + edgePr < flightCost[adjNode]){
                    flightCost[adjNode] = price + edgePr;
                    q.push({stops + 1, {adjNode, price + edgePr}});
                }
            }
        }
        
        if(flightCost[dst] == INT_MAX){
            return -1;
        }
        return flightCost[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends