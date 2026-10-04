class Solution:
    def longestCommonPrefix(self, strs: list[str]) -> str:
        ans=""
        prefix=strs[0]

        for i in range(0,len(strs[0])):
            ch=strs[0][i]

            for j in range(1,len(strs)):
                if i>=len(strs[j]) or strs[j][i]!=ch:
                    return ans

            ans+=ch

        return ans