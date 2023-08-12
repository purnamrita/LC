class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        map<int, int> pmap;
        for(char ch : p){
            pmap[ch]++;
        }

        map<int, int> smap;
        for(int i = 0; i < p.size() - 1; i++){
            smap[s[i]]++;
        }
        for(int i = p.size() - 1; i < s.size(); i++){
            smap[s[i]]++;
            if(i > p.size() - 1){
                smap[s[i - p.size()]]--;
                if(smap[s[i - p.size()]] == 0){
                    smap.erase(s[i - p.size()]);
                }
            }
            if(smap == pmap){
                ans.push_back(i - p.size() + 1);
            }
        }

        return ans;
    }
};