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
	    
	    vector<bool> prev(totSum + 1, false);
	    prev[0] = true;
	    prev[arr[0]] = true;
	    
	    for(int idx = 1; idx < n; idx++){
	        vector<bool> curr(totSum + 1, false);
	        curr[0] = true;
	        for(int tar = 1; tar <= totSum; tar++){
	            bool not_pick = prev[tar];
	            bool pick = false;
	            if(arr[idx] <= tar){
	                pick = prev[tar - arr[idx]];
	            }
	            curr[tar] = not_pick || pick;
	        }
	        prev = curr;
	    }
	    
	    int mini = INT_MAX;
	    for(int s = 0; s <= (totSum / 2); s++){
	        if(prev[s]){
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