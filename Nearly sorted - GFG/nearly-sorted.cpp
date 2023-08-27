//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int n, int K){
        priority_queue<int, vector<int>, greater<int>> minh;
        
        for(int i = 0; i <= K; i++){
            minh.push(arr[i]);
        }
        vector<int> ans;
        ans.push_back(minh.top());
        minh.pop();
        
        for(int i = K + 1; i < n; i++){
            minh.push(arr[i]);
            ans.push_back(minh.top());
            minh.pop();
        }
        
        while(!minh.empty()){
            ans.push_back(minh.top());
            minh.pop();
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num, K;
	    cin>>num>>K;
	    
	    int arr[num];
	    for(int i = 0; i<num; ++i){
	        cin>>arr[i];
	    }
	    Solution ob;
	    vector <int> res = ob.nearlySorted(arr, num, K);
	    for (int i = 0; i < res.size (); i++)
	        cout << res[i] << " ";
	        
	    cout<<endl;
	}
	
	return 0;
}

// } Driver Code Ends