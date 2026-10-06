class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        open_brack = 0
        add_needed = 0
        
        for ch in s:
            if ch == '(':
                open_brack += 1
            else:
                if open_brack > 0:
                    open_brack -= 1
                else:
                    add_needed += 1
                    
        return open_brack + add_needed


        