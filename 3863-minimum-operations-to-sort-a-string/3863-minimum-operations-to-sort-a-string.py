class Solution:
    def minOperations(self, s: str) -> int:
        if s == "".join(sorted(s)):
            return 0
        if len(s) == 2:
            return -1
            
        min_char = min(s)
        max_char = max(s)
        
        # 1 Operation check:
        # Min char is at the very beginning (not whole string) OR max char is at the very end (not whole string)
        if s[0] == min_char or s[-1] == max_char:
            return 1
            
        # 3 Operations check:
        # Unique max at start and unique min at end
        if s[0] == max_char and s[-1] == min_char and s.count(max_char) == 1 and s.count(min_char) == 1:
            return 3
            
        return 2