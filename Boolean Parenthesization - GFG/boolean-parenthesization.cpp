//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    int mod = 1003;
public:
    int helper(int i, int j, string &exp, bool isTrue, vector<vector<vector<int>>> &dp){
    if(i > j){
        return 0;
    }

    if(dp[i][j][isTrue] != -1){
        return dp[i][j][isTrue];
    }

    if(i == j){
        if(isTrue == 1){
            return (exp[i] == 'T') ? 1 : 0;
        }
        else{
            return (exp[i] == 'F') ? 1 : 0;
        }
    }

    int ways = 0;

    for(int idx = i + 1; idx < j; idx+=2){
        int lT = helper(i, idx - 1, exp, 1, dp);
        int lF = helper(i, idx - 1, exp, 0, dp);
        int rT = helper(idx + 1, j, exp, 1, dp);
        int rF = helper(idx + 1, j, exp, 0, dp);

        if(exp[idx] == '&'){
            if(isTrue == 1){
                ways = (ways % mod) + ((lT * rT) % mod);
            }
            else{
                ways = (ways % mod) + ((lT * rF) % mod) + ((lF * rT) % mod) + ((lF * rF) % mod);
            }
        }
        else if(exp[idx] == '|'){
            if(isTrue == 1){
                ways = (ways % mod) + ((lT * rT) % mod) + ((lT * rF) % mod) + ((lF * rT) % mod);
            }
            else{
                ways = (ways % mod) + ((lF * rF) % mod);
            }
        }
        else{
            if(isTrue == 1){
                ways = (ways % mod) + ((lT * rF) % mod) + ((lF * rT) % mod);
            }
            else{
                ways = (ways % mod) + ((lT * rT) % mod) + ((lF * rF) % mod);
            }
        }
    }

    return dp[i][j][isTrue] = (ways % mod);
}

    int countWays(int n, string exp){
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
        return helper(0, n - 1, exp, 1, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends