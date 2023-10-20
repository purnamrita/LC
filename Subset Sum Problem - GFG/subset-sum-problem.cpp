//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));
        
        for(int row = 0; row < n; row++){
            dp[row][0] = true; 
        }
        if(arr[0] <= sum){
            dp[0][arr[0]] = true;
        }
        
        for(int row = 1; row < n; row++){
            for(int target = 1; target <= sum; target++){
                bool not_pick = dp[row - 1][target];
                bool pick = false;
                if(arr[row] <= target){
                    pick = dp[row - 1][target - arr[row]];
                }
                dp[row][target] = pick || not_pick;
            }
        }
        
        return dp[n - 1][sum];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends