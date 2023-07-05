//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        if(n < 3){
            return false;
        }
        sort(A, A + n);
        for(int i = 0; i < n; i++){
            if(i > 0 && A[i] == A[i - 1]){
                continue;
            }
            int target = X - A[i];
            int lo = i + 1;
            int hi = n - 1;
            
            while(lo < hi){
                if(A[lo] + A[hi] == target){
                    return true;
                }
                else if(A[lo] + A[hi] < target){
                    lo++;
                    while(A[lo] == A[lo - 1]){
                        lo++;
                    }
                }
                else{
                    hi--;
                    while(A[hi] == A[hi + 1]){
                        hi--;
                    }
                }
            }
            
        }
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends