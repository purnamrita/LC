class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> adj[n];

        for(auto it : flights){
            int u = it[0];
            int v = it[1];
            int price = it[2];

            adj[u].push_back({v, price});
        }

        vector<int> cheapest(n, INT_MAX);
        queue<pair<int, pair<int, int>>> q; // (stops, node, cost)
        cheapest[src] = 0;
        q.push({0, {src, 0}});

        while(!q.empty()){
            auto it = q.front();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            q.pop();

            if(stops > k){
                continue;
            }

            for(auto it : adj[node]){
                int adjNode = it[0];
                int adjCost = it[1];

                if(cost + adjCost < cheapest[adjNode]){
                    cheapest[adjNode] = cost + adjCost;
                    q.push({stops + 1, {adjNode, cheapest[adjNode]}});
                }
            }
        }
        if(cheapest[dst] == INT_MAX){
            return -1;
        }
        return cheapest[dst];
    }
};