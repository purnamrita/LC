class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ans = 0;

        int l = 0;
        int r = n - 1;

        while(l < r){
            int width = r - l;
            int ht = min(height[l], height[r]);
            ans = max(ans, width * ht);

            if(height[l] < height[r]){
                l++;
            }
            else{
                r--;
            }
        } 

        return ans;
    }
};