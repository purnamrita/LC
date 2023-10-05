class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int ele;

        for(int num : nums){
            if(cnt == 0){
                ele = num;
                cnt++;
            }
            else if(ele == num){
                cnt++;
            }
            else{
                cnt--;
            }
        }

        return ele;
    }
};