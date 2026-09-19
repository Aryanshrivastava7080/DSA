class Solution:
    def permute(self, nums: list[int]) -> list[list[int]]:
        result = []
        
        def backtrack(start):
            if start == len(nums):
                result.append(nums[:])  # Append a copy of the current permutation
                return
            
            for i in range(start, len(nums)):
                nums[start], nums[i] = nums[i], nums[start]  # Swap
                backtrack(start + 1)
                nums[start], nums[i] = nums[i], nums[start]  # Backtrack (Unswap)

        backtrack(0)
        return result