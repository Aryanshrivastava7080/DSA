class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        char_map = {}  # Character ko uske last seen index se map karega
        left = 0
        max_len = 0

        for right in range(len(s)):
            ch = s[right]
            
            # Agar character pehle mil chuka hai aur wo current window ke andar hai
            if ch in char_map and char_map[ch] >= left:
                left = char_map[ch] + 1  # Window ki left boundary aage badhao
            
            char_map[ch] = right  # Character ka index store / update karo
            max_len = max(max_len, right - left + 1)

        return max_len
       
        