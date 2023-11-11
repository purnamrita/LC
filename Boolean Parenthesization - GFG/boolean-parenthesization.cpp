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

    int countWays(int n, string exp){
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(2, -1)));
        
        for(int i = 0; i < n; i++){
            dp[i][i][0] = (exp[i] == 'F');
            dp[i][i][1] = (exp[i] == 'T');
        }
        
        for(int i = n - 1; i >= 0; i--){
            for(int j = 0; j <= n - 1; j++){
                for(int isTrue = 0; isTrue <= 1; isTrue++){
                    if(i == j){
                        continue;
                    }
                    int ways = 0;
                
                    for(int idx = i + 1; idx < j; idx+=2){
                        int lT = dp[i][idx - 1][1];
                        int lF = dp[i][idx - 1][0];
                        int rT = dp[idx + 1][j][1];
                        int rF = dp[idx + 1][j][0];
                
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

                    dp[i][j][isTrue] = (ways % mod);
                }
            }
        }
        
        return dp[0][n - 1][1];
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