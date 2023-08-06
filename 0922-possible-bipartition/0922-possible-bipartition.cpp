class Solution {
public:
    bool checkBipartite(int node, int col, vector<vector<int>> &adj, vector<int> &color){
        color[node] = col;
        for(int it : adj[node]){
            if(color[it] == -1){
                if(checkBipartite(it, !col, adj, color) == false){
                    return false;
                }
            }
            else{
                if(color[it] == col){
                    return false;
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n);

        for(auto it : dislikes){
            int u = it[0];
            int v = it[1];
            adj[u - 1].push_back(v - 1);
            adj[v - 1].push_back(u - 1);
        }

        vector<int> color(n, -1);

        for(int i = 0; i < n; i++){
            if(color[i] == -1){
                if(checkBipartite(i, 0, adj, color) == false){
                    return false;
                }
            }
        }

        return true;
    }
};