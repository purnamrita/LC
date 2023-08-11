class Solution {
public:
    int lengthOfLongestSubstring(string s){
	int ans = 0;
	unordered_set<char> st;
	int l = 0;
	int r = 0;
	
	while(r < s.length()){
		if(st.find(s[r]) == st.end()){
			st.insert(s[r]);
			ans = max(ans, r- l + 1);
			r++;
}
else{
	while(st.find(s[r]) != st.end()){
		st.erase(s[l]);
		l++;
}
}
}
return ans;
}

};