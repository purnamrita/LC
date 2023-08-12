//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        unordered_map<char, int> whole;
        unordered_map<char, int> sub;
        
        for(auto ch : str){
            whole[ch]++;
        }
        
        int ans = str.size();
        
        int start = 0;
        int end = 0;
        
        while(end < str.size()){
            sub[str[end]]++;
            
            if(whole.size() == sub.size()){
                ans = min(ans, end - start + 1);
                
                while(whole.size() == sub.size()){
                    ans = min(ans, end - start + 1);
                    sub[str[start]]--;
                    if(sub[str[start]] == 0){
                        sub.erase(str[start]);
                    }
                    start++;
                }
            }
            
            end++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends