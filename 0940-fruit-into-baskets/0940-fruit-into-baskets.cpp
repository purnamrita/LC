class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
	int ans = 0;
	unordered_map<int, int> umap;
	int left = 0;
	int right = 0;

	while(right < n){
		umap[fruits[right]]++;
		
		while(umap.size() > 2){
			umap[fruits[left]]--;
			if(umap[fruits[left]] == 0){
				umap.erase(fruits[left]);
}
left++;
}

ans = max(ans, right - left + 1);
right++;
}

return ans;

    }
};