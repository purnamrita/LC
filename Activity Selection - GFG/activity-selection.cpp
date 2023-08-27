//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    struct job{
        int start;
        int end;
    };
    
    static bool comp(struct job j1, struct job j2){
        if(j1.end < j2.end){
            return true;
        }
        return false;
    }
    
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        struct job arr[n];
        
        for(int i = 0; i < n; i++){
            arr[i].start = start[i];
            arr[i].end = end[i];
        }
        
        sort(arr, arr + n, comp);
        
        int ans = 1;
        int limit = arr[0].end;
        
        for(int i = 1; i < n; i++){
            if(arr[i].start > limit){
                ans++;
                limit = arr[i].end;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}

// } Driver Code Ends