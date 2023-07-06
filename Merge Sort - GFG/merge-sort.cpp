//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
         vector<int> temp(r - l + 1);
         int idx = 0;
         // First: l to mid
         // Second: mid + 1 to r
         int i = l;
         int j = m + 1;
         
         while(i <= m && j <= r){
             if(arr[i] <= arr[j]){
                 temp[idx] = arr[i];
                 idx++;
                 i++;
             }
             else{
                 temp[idx] = arr[j];
                 idx++;
                 j++;
             }
         }
         
         while(i <= m){
             temp[idx] = arr[i];
             idx++;
             i++;
         }
         
         while(j <= r){
             temp[idx] = arr[j];
             idx++;
             j++;
         }
         
         int n = r - l + 1;
         for(int i = 0; i < n; i++){
             arr[l + i] = temp[i];
         }
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        if(l < r){
            int mid = l + (r - l) / 2;
            mergeSort(arr, l, mid);
            mergeSort(arr, mid + 1, r);
            merge(arr, l, mid, r);
        }
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends