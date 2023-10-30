//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    int n = nums.size();
	    vector<int> left(n, 1);
	    vector<int> right(n, 1);
	    
	    for(int idx = 0; idx < n; idx++){
	        for(int prev = 0; prev < idx; prev++){
	            if(nums[prev] < nums[idx] && left[prev] + 1 > left[idx]){
	                left[idx] = left[prev] + 1;
	            }
	        }
	    }
	    
	    for(int idx = n - 1; idx >= 0; idx--){
	        for(int prev = n - 1; prev > idx; prev--){
	            if(nums[prev] < nums[idx] && right[prev] + 1 > right[idx]){
	                right[idx] = right[prev] + 1;
	            }
	        }
	    }
	    
	    int maxLen = 0;
	    
	    for(int i = 0; i < n; i++){
	        maxLen = max(maxLen, right[i] + left[i] - 1);
	    }
	    
	    return maxLen;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends