//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    int cnt = 0;
	    map<int, int> pmap;
	    for(char ch : pat){
	        pmap[ch]++;
	    }
	    
	    map<int, int> tmap;
	    for(int i = 0; i < pat.size() - 1; i++){
	        tmap[txt[i]]++;
	    }
	    
	    for(int i = pat.size() - 1; i < txt.size(); i++){
	        tmap[txt[i]]++;
	        if(i > pat.size() - 1){
	            tmap[txt[i - pat.size()]]--;
	            if(tmap[txt[i - pat.size()]] == 0){
	                tmap.erase(txt[i - pat.size()]);
	            }
	        }
	        if(tmap == pmap){
	            cnt++;
	        }
	    }
	    return cnt;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends