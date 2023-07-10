class Solution {
public:
    void bfs(int node, vector<int> adj[], vector<int> &vis){
        queue<int> q;
        vis[node] = 1;
        q.push(node);

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto it : adj[curr]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<int> adj[V + 1];

        for(int i = 1; i <= V; i++){
            for(int j = 1; j <= V; j++){
                if(isConnected[i - 1][j - 1] == 1 & i != j){
                    adj[i].push_back(j);
                }
            }
        }

        int cnt = 0;
        vector<int> vis(V + 1);
        for(int i = 1; i <= V; i++){
            if(!vis[i]){
                cnt++;
                bfs(i, adj, vis);
            }
        }
        return cnt;
    }
};