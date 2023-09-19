//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        
        if(start == end){
            return 0;
        }
        vector<int> dist(100000, INT_MAX);
        queue<pair<int, int>> q; //(steps, node)
        dist[start] = 0;
        q.push({0, start});
        int mod = 100000;
        
        while(!q.empty()){
            int steps = q.front().first;
            int curr = q.front().second;
            q.pop();
            
            for(int num : arr){
                int newNum = (num * curr) % mod;
                if(steps + 1 < dist[newNum]){
                    dist[newNum] = steps + 1;
                    if(newNum == end){
                        return steps + 1;
                    }
                    q.push({steps + 1, newNum});
                }
            }
        }
        
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends