class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<int> &vis){
        vis[node] = 1;

        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it, adj, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<int> adj[n];

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i != j && isConnected[i][j] == 1){
                    adj[i].push_back(j);
                }
            }
        }

        vector<int> vis(n);

        int provinces = 0;

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i, adj, vis);
                provinces++;
            }
        }

        return provinces;
    }
};