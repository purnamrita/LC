class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> topo;

        vector<int> adj[numCourses];

        for(auto it : prerequisites){
            int a = it[0];
            int b = it[1];

            adj[b].push_back(a);
        }

        queue<int> q;
        vector<int> indegree(numCourses);

        for(auto v : adj){
            for(auto it : v){
                indegree[it]++;
            }
        }

        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }

        if(topo.size() != numCourses){
            return {};
        }
        return topo;
    }
};