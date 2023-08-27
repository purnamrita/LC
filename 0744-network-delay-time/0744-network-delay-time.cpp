class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> adj[n + 1];

        for(int i = 0; i < times.size(); i++){
            int u = times[i][0];
            int v = times[i][1];
            int dist = times[i][2];

            adj[u].push_back({v, dist});
        }

        vector<int> time(n + 1, INT_MAX);
        time[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minh; // (time, node)
        minh.push({0, k});

        while(!minh.empty()){
            int node = minh.top().second;
            int timeTillHere = minh.top().first;
            minh.pop();

            for(auto it : adj[node]){
                int adjNode = it[0];
                int adjTime = it[1];
                if(timeTillHere + adjTime < time[adjNode]){
                    time[adjNode] = timeTillHere + adjTime;
                    minh.push({time[adjNode], adjNode});
                }
            }
        }  

        int maxTime = INT_MIN;
        for(int i = 1; i <= n; i++){
            if(time[i] == INT_MAX){
                return -1;
            }
            maxTime = max(maxTime, time[i]);
        }
        return maxTime;
    }
};