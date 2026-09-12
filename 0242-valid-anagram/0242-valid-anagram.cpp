class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        // Step 2: 26 lowercase English alphabets ke liye array
        int count[26] = {0};

        // Step 3: Frequency count karein
        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++; // s ke character ki count badao
            count[t[i] - 'a']--; // t ke character ki count ghatao
        }

        // Step 4: Check karein ki saare counts 0 hue ya nahi
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) {
                return false;
            }
        } 

        return true;
        
    }
};