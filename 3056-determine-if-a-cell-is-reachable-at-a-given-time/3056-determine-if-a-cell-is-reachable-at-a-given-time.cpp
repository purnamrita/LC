class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int diffx = abs(sx - fx);
        int diffy = abs(sy - fy);
        int diag = min(diffx, diffy);

        int timeMin = diag + (max(diffx, diffy) - diag);

        if(timeMin == 0){
            return (t != 1);
        }
        return (t >= timeMin);
    }
};