class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate=0;
        int count=0;
        int n= nums.size();

        for(int i=0; i<n; i++){
            int num= nums[i];

            if(count==0){
                candidate=num;
                count=1;
            }
            else if(num==candidate){
                count++;
            }
            else{
                count--;
            }
        }
        return candidate;
        }
};
//         sort(nums.begin(), nums.end());
//         int n = nums.size();
//         return nums[n/2];
//     }
// };
//         int candidate=0;
//         int count=0;

//         for(int i=0; i<nums.size(); i++){

//             int num = nums[i];

//             if(count==0){
//                 candidate = num;
//                 count=1;
//             }
//             else if(num == candidate){
//                 count++;
//             }
//             else{
//                 count--;
//             }
//         }
//         return candidate;
//     }
// };