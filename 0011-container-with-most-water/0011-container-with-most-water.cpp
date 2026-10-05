class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int max_water = 0;
        int lp = 0; //leftpointer
        int rp = n-1; //rightpointer

        while(lp < rp){
            int w = rp - lp;
            int h = min(height[lp], height[rp]);
            int area = w * h;
            max_water = max(area, max_water);

            if(height[lp] > height[rp]){
                rp--;
            }
            else{
                lp++;
            }
        }

        return max_water;
    }
};