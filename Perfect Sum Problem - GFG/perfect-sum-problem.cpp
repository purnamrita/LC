//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int mod = 1e9 + 7;
	int helper(int idx, int arr[], int target, vector<vector<int>> &dp){
	    
	    if(idx == 0){
	        if(target == 0 && arr[0] == 0){
	            return dp[idx][target] = 2;
	        }
	        if(target == 0 || arr[0] == target){
	            return dp[idx][target] = 1;
	        }
	        return dp[idx][target] = 0;
	    }
	    
	    if(dp[idx][target] != -1){
	        return dp[idx][target] % mod;
	    }
	    
	    int not_pick = helper(idx - 1, arr, target, dp) % mod;
	    int pick = 0;
	    if(arr[idx] <= target){
	        pick = helper(idx - 1, arr, target - arr[idx], dp) % mod;
	    }
	    return dp[idx][target] = (not_pick + pick) % mod;
	}
	
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return helper(n - 1, arr, sum, dp) % mod;
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends