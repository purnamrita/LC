class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxh;

        for(int stone: stones){
            maxh.push(stone);
        }

        while(maxh.size() >= 2){
            int y = maxh.top();
            maxh.pop();
            int x = maxh.top();;
            maxh.pop();

            if(x == y){
                continue;
            }
            else{
                maxh.push(y - x);
            }
        }

        if(maxh.size() == 1){
            return maxh.top();
        }
        return 0;
    }
};