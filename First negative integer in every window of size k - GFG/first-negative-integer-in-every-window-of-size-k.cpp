//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends

void putFirstNeg(vector<long long> &ans, deque<long long> &dq){
    if(dq.empty()){
        ans.push_back(0);
    }
    else{
        ans.push_back(dq.front());
    }
}

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    vector<long long> ans;
    deque<long long> dq;
    for(int i = 0; i < K; i++){
        if(A[i] < 0){
            dq.push_back(A[i]);
        }
    }
    putFirstNeg(ans, dq);
    for(int i = K; i < N; i++){
        if(A[i] < 0){
            dq.push_back(A[i]);
        }
        if(dq.front() == A[i - K]){
            dq.pop_front();
        }
        putFirstNeg(ans, dq);
    }
    return ans;
                                                 
 }