class Solution:
    def isPalindrome(self, x: int) -> bool:
        ans=0
        target=x
        if target<0:
            return False
        while x:
            digit=x%10
            ans=ans*10+digit
            x=x//10

        if ans==target:
            return True
        else:
            return False