class Solution {
public:
    int mod = 1e9 + 7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int ans = 1;

        unordered_map<int, long long> mp;
        mp[arr[0]] = 1;

        for(int i = 1; i < n; i++){
            int parent = arr[i];
            int cnt = 1;
            for(int j = 0; j < i; j++){
                if(arr[i] % arr[j] == 0){
                    int leftChild = arr[j];
                    int rightChild = parent / leftChild;
                    if(mp.find(rightChild) != mp.end()){
                        cnt = (cnt + (mp[leftChild] * mp[rightChild]) % mod) % mod;
                    }
                }
            }
            mp[parent] = cnt % mod;
            ans += (cnt % mod);
            ans = ans % mod;
        }

        return ans % mod;
    }
};