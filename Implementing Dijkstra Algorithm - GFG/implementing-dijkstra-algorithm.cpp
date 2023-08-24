//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minh;  //(dist, node)
        vector<int> distance(V);
        for(int i = 0; i < V; i++){
            distance[i] = INT_MAX;
        }
        distance[S] = 0;
        
        minh.push({0, S});
        
        while(!minh.empty()){
            int node = minh.top().second;
            int dist = minh.top().first;
            minh.pop();
            
            for(auto it : adj[node]){
                int adjNode = it[0];
                int edgeWt = it[1];
                
                if(dist + edgeWt < distance[adjNode]){
                    distance[adjNode] = dist + edgeWt;
                    minh.push({distance[adjNode], adjNode});
                }
            }
        }
        
        return distance;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends