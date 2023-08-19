class Solution {
public:
    bool dfs(int node, vector<int> &vis, vector<int> adj[], int destination){
        vis[node] = 1;
        for(auto n : adj[node]){
            if(!vis[n]){
                if(n == destination){
                    return true;
                }
                if(dfs(n, vis, adj, destination) == true){
                    return true;
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination){
            return true;
        }
        vector<int> adj[n];

        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n);

        return dfs(source, vis, adj, destination);
        
    }
};