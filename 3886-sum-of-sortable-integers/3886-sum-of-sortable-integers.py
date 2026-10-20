class Solution:
    def sortableIntegers(self, nums: list[int]) -> int:
        n = len(nums)
        sorted_nums = sorted(nums)
        total_sum = 0
        
        # Precompute prefix matches or check divisors efficiently
        for k in range(1, n + 1):
            if n % k != 0:
                continue
                
            possible = True
            for i in range(0, n, k):
                sub_orig = nums[i:i + k]
                sub_sorted = sorted_nums[i:i + k]
                
                if sub_orig == sub_sorted:
                    continue
                
                # Fast rotation check using string representation or optimized matching
                # Concatenating with itself avoids inner loops in python for rotation check
                s_orig = "".join(map(str, sub_orig))
                s_sorted = "".join(map(str, sub_sorted))
                
                if s_sorted not in (s_orig + s_orig):
                    possible = False
                    break
                    
            if possible:
                total_sum += k
                
        return total_sum