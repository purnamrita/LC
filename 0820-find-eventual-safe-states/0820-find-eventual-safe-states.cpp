class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int> &vis, vector<int> &pathVis, vector<int> &ans){
        vis[node] = 1;
        pathVis[node] = 1;

        for(auto it : graph[node]){
            if(!vis[it]){
                if(dfs(it, graph, vis, pathVis, ans) == true){
                    return true;
                }
            }
            else{
                if(pathVis[it] == 1){
                    return true;
                }
            }
        }

        pathVis[node] = 0;
        ans.push_back(node);
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        int n = graph.size();
        vector<int> vis(n, 0);
        vector<int> pathVis(n, 0);

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i, graph, vis, pathVis, ans);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};