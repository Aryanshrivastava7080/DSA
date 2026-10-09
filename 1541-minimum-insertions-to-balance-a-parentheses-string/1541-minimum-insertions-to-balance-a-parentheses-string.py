class Solution:
    def minInsertions(self, s: str) -> int:
        res = 0
        open_cnt = 0
        i = 0
        n = len(s)
        
        while i < n:
            if s[i] == '(':
                open_cnt += 1
            else:
                if i + 1 < n and s[i + 1] == ')':
                    i += 1
                    if open_cnt > 0:
                        open_cnt -= 1
                    else:
                        res += 1
                else:
                    res += 1  # Need 1 ')' to make it '))'
                    if open_cnt > 0:
                        open_cnt -= 1
                    else:
                        res += 1  # Need 1 '('
            i += 1
            
        res += open_cnt * 2
        return res