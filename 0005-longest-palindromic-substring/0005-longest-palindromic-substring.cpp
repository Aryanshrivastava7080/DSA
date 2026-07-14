class Solution {
public:
      
    string longestPalindrome(string s) {
        int start=0;
        int maxlen=1;
        int n= s.length();

        for(int i=0; i<n; i++){
            
            // odd condition
            int left=i;
            int rght=i;

            while(left>=0 && rght<n && s[left]==s[rght]){
                if(rght-left+1>maxlen){
                    maxlen=rght-left+1;
                    start=left;
                }
                left--;
                rght++;
            }

            // even
             left=i;
             rght=i+1;
            while(left>=0 && rght<n && s[left]==s[rght]){
                if(rght-left+1>maxlen){
                    maxlen=rght-left+1;
                    start=left;
                }
                left--;
                rght++;
            }
        }
       return s.substr(start,maxlen);

    }
};
//         int start = 0;
//         int maxLen = 1;

//         for (int i = 0; i < s.length(); i++) {

//             // Odd length palindrome
//             int left = i;
//             int right = i;

//             while (left >= 0 && right < s.length() && s[left] == s[right]) {

//                 if (right - left + 1 > maxLen) {
//                     maxLen = right - left + 1;
//                     start = left;
//                 }

//                 left--;
//                 right++;
//             }

//             // Even length palindrome
//             left = i;
//             right = i + 1;

//             while (left >= 0 && right < s.length() && s[left] == s[right]) {

//                 if (right - left + 1 > maxLen) {
//                     maxLen = right - left + 1;
//                     start = left;
//                 }

//                 left--;
//                 right++;
//             }
//         }

//         return s.substr(start, maxLen);
//     }
// };