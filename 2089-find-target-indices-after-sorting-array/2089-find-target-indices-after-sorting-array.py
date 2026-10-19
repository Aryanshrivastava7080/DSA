class Solution:
    def targetIndices(self, nums: list[int], target: int) -> list[int]:
        n=sorted(nums)

        return [i for i, val in enumerate(n) if val == target]
