class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n= nums.size();
        int i,j;
        for( i=0; i<n; i++){
            for( j=i+1; j<n; j++){
                if(nums[i]+nums[j]==target){
                    return{i,j};
                }
            }
        }
        return{i,j};
    }
};
       
//         unordered_map<int, int> mp;
//         for(int i = 0; i < nums.size(); i++) {
//             int rem = target - nums[i];

//             if(mp.find(rem) != mp.end()) {
//                 return {mp[rem], i};
//         }

//         mp[nums[i]] = i;
//     }

//     return {};
//     }

// };
  