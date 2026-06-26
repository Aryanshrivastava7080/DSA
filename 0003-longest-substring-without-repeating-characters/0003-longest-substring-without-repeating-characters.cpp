class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;

        int left = 0;
        int ans = 0;

        for(int right = 0; right < s.size(); right++)
        {
            while(st.count(s[right]))
            {
                st.erase(s[left]);
                left++;
            }

            st.insert(s[right]);

            ans = max(ans, right-left+1);
        }

        return ans;
    }
    //     int n= s.size();
    //     int ans=0;
    //     unordered_map<char,int>mp;

    //     for(int i=0; i<n; i++){
    //         unordered_map<char,int>mp;
    //         for(int j=i; j<n; j++){
    //             if(mp[s[j]]>0){
    //                 break;
    //             }
    //             mp[s[j]]++;
    //             ans= max(ans,j-i+1);    
    //         }
           
    //     }
    //     return ans;    
    // }
};