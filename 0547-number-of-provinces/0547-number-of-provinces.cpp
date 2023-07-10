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
        int V = isConnected.size();
        vector<int> adj[V + 1];

        vector<int> vis(V + 1);

        for(int i = 1; i <= V; i++){
            for(int j = 1; j <= V; j++){
                if(isConnected[i - 1][j - 1] == 1 && i != j){
                    adj[i].push_back(j);
                }
            }
        }

        int cnt = 0;
        for(int i = 1; i <= V; i++){
            if(!vis[i]){
                dfs(i, adj, vis);
                cnt++;
            }
        }

        return cnt;
    }
};