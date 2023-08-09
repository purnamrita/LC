class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];

        for(auto it: prerequisites){
            int b = it[0];
            int a  = it[1];

            adj[b].push_back(a);
        }

        vector<int> indegree(numCourses);

        for(auto v : adj){
            for(auto it : v){
                indegree[it]++;
            }
        }

        queue<int> q;
        vector<int> topo;

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

        return (topo.size() == numCourses);
    }
};