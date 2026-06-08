class Solution {
public:
    int maxArea(vector<int>& height) {
        int lft=0, rght=height.size()-1;
        int maxWater=0;

        while(lft < rght){
            int width= rght-lft;
            int h= min(height[lft],height[rght]);
            int area=width*h;
            maxWater=max(maxWater,area);

            if(height[lft]<height[rght]){
                lft++;
            }
            else{
                rght--;
            }
        }
        return maxWater;
    }
};