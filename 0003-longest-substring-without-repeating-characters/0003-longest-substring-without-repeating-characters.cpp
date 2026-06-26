class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n= s.size();
        int ans=0;
        unordered_map<char,int>mp;

        for(int i=0; i<n; i++){
             unordered_map<char,int>mp;
            for(int j=i; j<n; j++){
                if(mp[s[j]]>0){
                    break;
                }
                mp[s[j]]++;
                ans= max(ans,j-i+1);    
            }
           
        }
        return ans;    
    }
};