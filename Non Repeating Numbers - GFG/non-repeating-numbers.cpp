//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        int n = nums.size();
        int xorr = 0;
        for(int i = 0; i < n; i++){
            xorr = xorr ^ nums[i];
        }
        int rightone = xorr & ~(xorr - 1);
        int set1 = 0;
        int set2 = 0;
        
        for(int i = 0; i < n; i++){
            if(nums[i] & rightone){
                set1 ^= nums[i];
            }
            else{
                set2 ^= nums[i];
            }
        }
        
        vector<int> ans = {set1, set2};
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends