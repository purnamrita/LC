//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long KthSmallest(long long A[], long long N, long long K){
        priority_queue<int> maxh;
        
        for(int i = 0; i < N; i++){
            maxh.push(A[i]);
            
            if(maxh.size() > K){
                maxh.pop();
            }
        }
        
        return maxh.top();
    }
    
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
        int num1 = KthSmallest(A, N, K1);
        int num2 = KthSmallest(A, N, K2);
        
        long long sum = 0;
        
        for(int i = 0; i < N; i++){
            if(A[i] > num1 && A[i] < num2){
                sum += A[i];
            }
        } 
        
        return sum;
    }
};

//{ Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}

// } Driver Code Ends