from collections import deque

class Solution:
    def removeInvalidParentheses(self, s: str) -> list[str]:
        def isValid(string):
            count = 0
            for ch in string:
                if ch == '(':
                    count += 1
                elif ch == ')':
                    count -= 1
                    if count < 0:
                        return False
            return count == 0

        res = []
        visited = set([s])
        queue = deque([s])
        found = False

        while queue:
            curr = queue.popleft()
            
            if isValid(curr):
                res.append(curr)
                found = True  # Is level par valid string mil gayi
            
            if found:
                continue  # Key optimization: aage ke sub-levels add mat karo
            
            # Sub-strings generate karo ek character remove karke
            for i in range(len(curr)):
                if curr[i] not in ('(', ')'):
                    continue
                next_str = curr[:i] + curr[i+1:]
                if next_str not in visited:
                    visited.add(next_str)
                    queue.append(next_str)

        return res