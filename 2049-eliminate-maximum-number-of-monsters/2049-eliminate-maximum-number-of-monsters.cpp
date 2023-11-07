class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<double> time(n);

        for(int i = 0; i < n; i++){
            time[i] = (double)dist[i] / (double)speed[i];
        }
        sort(time.begin(), time.end());

        int weap = 0;

        for(int i = 0; i < n; i++){
            if(weap < time[i]){
                weap++;
            }
            else{
                return weap;
            }
        }

        return weap;
    }
};