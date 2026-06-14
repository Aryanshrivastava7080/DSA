class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea=0;
        int lft=0;
        int rght=height.size()-1;

       while(lft<rght){
        maxArea = max(maxArea, (rght-lft)*min(height[lft],height[rght]) );

        if(height[lft]<height[rght]){
            lft++;
        }else{
            rght--;
        }
       }
       return maxArea;
    }
};
//         int maxArea = 0;
//         int left = 0;
//         int right = height.size() - 1;

//         while (left < right) {
//             maxArea = max(maxArea, (right - left) * min(height[left], height[right]));

//             if (height[left] < height[right]) {
//                 left++;
//             } else {
//                 right--;
//             }
//         }

//         return maxArea;        
//     }
// };