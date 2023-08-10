class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue< pair<int, pair<int, int>>> maxh;

        int n = points.size();

        for(int i = 0; i < n; i++){
            int x = points[i][0];
            int y = points[i][1];
            int dist = x*x + y*y;

            maxh.push({dist, {x, y}});

            if(maxh.size() > k){
                maxh.pop();
            }
        }

        vector<vector<int>> ans;

        while(!maxh.empty()){
            int x = maxh.top().second.first;
            int y = maxh.top().second.second;
            maxh.pop();
            ans.push_back({x, y});
        }

        return ans;
    }
};