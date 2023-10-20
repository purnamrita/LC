//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int helper(int idx, int target, vector<int> arr, vector<vector<int>> &dp){
        if(target == 0){
            return dp[idx][target] = true;
        }
        if(idx == 0){
            return (target == arr[0]);
        }
        if(dp[idx][target] != -1){
            return dp[idx][target];
        }
        bool not_pick = helper(idx - 1, target, arr, dp);
        bool pick = false;
        if(arr[idx] <= target){
            pick = helper(idx - 1, target - arr[idx], arr, dp);
        }
        return dp[idx][target] = pick || not_pick;
    }
    
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return helper(n - 1, sum, arr, dp);
        
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