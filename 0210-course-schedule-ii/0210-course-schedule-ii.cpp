class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];

        for(auto it : prerequisites){
            int a = it[0];
            int b = it[1];
            adj[b].push_back(a);
        }

        vector<int> indegree(numCourses);
        for(auto v : adj){
            for(int node : v){
                indegree[node]++;
            }
        }

        queue<int> q;
        for(int i = 0; i < indegree.size(); i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(int n : adj[node]){
                indegree[n]--;
                if(indegree[n] == 0){
                    q.push(n);
                }
            }
        }

        if(topo.size() == numCourses){
            return topo;
        }
        return {};
    }
};