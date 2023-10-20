//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    int totSum = 0;
	    for(int i = 0; i < n; i++){
	        totSum += arr[i];
	    }
	    
	    vector<vector<bool>> dp(n, vector<bool>(totSum + 1, false));
	    
	    for(int row = 0; row < n; row++){
	        dp[row][0] = true;
	    }
	    dp[0][arr[0]] = true;
	    
	    for(int idx = 1; idx < n; idx++){
	        for(int tar = 1; tar <= totSum; tar++){
	            bool not_pick = dp[idx - 1][tar];
	            bool pick = false;
	            if(arr[idx] <= tar){
	                pick = dp[idx - 1][tar - arr[idx]];
	            }
	            dp[idx][tar] = not_pick || pick;
	        }
	    }
	    
	    int mini = INT_MAX;
	    for(int s = 0; s <= (totSum / 2); s++){
	        if(dp[n - 1][s]){
	            int s1 = s;
	            int s2 = totSum - s1;
	            mini = min(mini, abs(s1 - s2));
	        }
	    }
	    
	    return mini;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends