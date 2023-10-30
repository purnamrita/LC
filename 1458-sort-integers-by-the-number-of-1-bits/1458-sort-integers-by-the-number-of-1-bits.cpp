class Solution {
public:
    int count1Bits(int n){
        int ans = 0;
        for(int i = 0; i < 32; i++){
            if((n & (1 << i)) != 0){
                ans++;
            }
        }
        return ans;
    }

    vector<int> sortByBits(vector<int>& arr) {
        vector<int> ans;
        map<int, vector<int>> mp;
        for(int num : arr){
            int cnt1 = count1Bits(num);
            mp[cnt1].push_back(num);
        }

        for(auto it : mp){
            vector<int> temp = it.second;
            sort(temp.begin(), temp.end());
            for(int num : temp){
                ans.push_back(num);
            }
        }

        return ans;
    }
};