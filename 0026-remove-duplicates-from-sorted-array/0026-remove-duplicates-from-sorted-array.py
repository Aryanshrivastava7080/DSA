class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        # ans=0
        # for i in range(1,len(nums)):
        #     if nums[nums]!=nums[i]:
        #         ans+=1
        #         nums[ans]=nums[i]
        # return ans+1




















        ans=0
        for i in range(1,len(nums)):
            if nums[ans]!=nums[i]:
                ans+=1
                nums[ans]=nums[i]
        return ans+1
