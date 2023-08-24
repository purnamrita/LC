class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> adj[n + 1];
        for(auto vt : times){
            int u = vt[0];
            int v = vt[1];
            int wt = vt[2];
            adj[u].push_back({v, wt});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> distance(n + 1, INT_MAX);
        distance[k] = 0;
        pq.push({0, k});

        while(!pq.empty()){
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it : adj[node]){
                int adjNode = it[0];
                int edgeWt = it[1];

                if(dist + edgeWt < distance[adjNode]){
                    distance[adjNode] = dist + edgeWt;
                    pq.push({distance[adjNode], adjNode});
                }
            }
        }

        int time = INT_MIN;
        for(int i = 1; i <= n; i++){
            if(distance[i] == INT_MAX){
                return -1;
            }
            time = max(time, distance[i]);
        }
        return time;
    }
};