//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool comp(struct Item i1, struct Item i2){
        double vw1 = (double)i1.value / (double)i1.weight;
        double vw2 = (double)i2.value / (double)i2.weight;
        return vw1 > vw2;
    }
    
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        double ans = 0;
        sort(arr, arr + n, comp);
        
        for(int i = 0; i < n; i++){
            if(W >= arr[i].weight){
                W -= arr[i].weight;
                ans += arr[i].value;
            }
            else{
                ans += ((double)W / (double)arr[i].weight) * arr[i].value;
                W = 0;
                break;
            }
        }
        return ans;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends