class Solution {
public:
    bool dfs(int src, int col, vector<vector<int>>& graph, vector<int> &color){
        color[src] = col;

        for(auto it : graph[src]){
            if(color[it] == -1){
                if(dfs(it, !col, graph, color) == false){
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
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for(int i = 0; i < n; i++){
            if(color[i] == -1){
                if(dfs(i, 0, graph, color) == false){
                    return false;
                }
            }
        }

        return true;
    }
};