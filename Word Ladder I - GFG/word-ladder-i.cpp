//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        set<string> s(wordList.begin(), wordList.end());
        s.erase(startWord);
        
        queue<pair<string, int>> q;
        q.push({startWord, 1});
        
        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            if(word == targetWord){
                return steps;
            }
            
            for(int i = 0; i < word.size(); i++){
                for(char ch = 'a'; ch <= 'z'; ch++){
                    char original = word[i];
                    word[i] = ch;
                    
                    if(s.find(word) != s.end()){
                        s.erase(word);
                        q.push({word, steps + 1});
                    }
                    
                    word[i] = original;
                }
            }
        }
        
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends