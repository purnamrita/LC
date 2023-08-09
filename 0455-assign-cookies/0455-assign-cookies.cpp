class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());

        int g_child = g.size() - 1;
        int s_cookie = s.size() - 1;
        int cnt = 0;

        while(s_cookie >= 0 && g_child >= 0){
            if(s[s_cookie] >= g[g_child]){
                cnt++;
                s_cookie--;
                g_child--;
            }
            else{
                g_child--;
            }
        }

        return cnt;
    }
};