//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
private:
    bool isValid(int row, int col, int n, int m){
        return (row >= 0 && row < n && col >= 0 && col < m);
    }
public:
    int Count(vector<vector<int> >& matrix) {
        int n = matrix.size();  //rows
        int m = matrix[0].size();  //cols
        
        int delRow[] = {0, -1, -1, -1, 0, 1, 1, 1};
        int delCol[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 1){
                    int cnt = 0;
                    for(int k = 0; k < 8; k++){
                        int newr = i + delRow[k];
                        int newc = j + delCol[k];
                        if(isValid(newr, newc, n, m) && matrix[newr][newc] == 0){
                            cnt++;
                        }
                    }
                    if(cnt != 0 && cnt % 2 == 0){
                        ans++;
                    }
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends