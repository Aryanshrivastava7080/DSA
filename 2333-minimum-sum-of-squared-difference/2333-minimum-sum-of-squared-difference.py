from collections import Counter

class Solution:
    def minSumSquareDiff(self, nums1: list[int], nums2: list[int], k1: int, k2: int) -> int:
        n = len(nums1)
        total_k = k1 + k2
        
        # Step 1: Find absolute differences
        diffs = [abs(nums1[i] - nums2[i]) for i in range(n)]
        
        # If total sum of differences is already within operations or max diff is 0
        if sum(diffs) <= total_k:
            return 0
            
        # Step 2: Count frequencies of each difference
        count = Counter(diffs)
        unique_diffs = sorted(count.keys(), reverse=True)
        
        # Step 3: Greedily reduce using batch subtraction
        for i in range(len(unique_diffs)):
            d = unique_diffs[i]
            if d == 0:
                break
                
            # Next smaller unique difference (agar last element hai toh 0 maan lo)
            next_d = unique_diffs[i + 1] if i + 1 < len(unique_diffs) else 0
            
            freq = count[d]
            # Kitne steps mein hum current difference 'd' ko 'next_d' tak laa sakte hain
            diff_height = d - next_d
            max_ops_possible = freq * diff_height
            
            if total_k >= max_ops_possible:
                # Saare 'd' frequency wale elements ko 'next_d' tak ghata sakte hain
                total_k -= max_ops_possible
                count[d] = 0
                count[next_d] += freq
            else:
                # Jitne operations bache hain, unhe distribute karo
                full_steps = total_k // freq
                remainder = total_k % freq
                
                count[d] -= freq
                count[d - full_steps] += freq - remainder
                if d - full_steps - 1 >= 0:
                    count[d - full_steps - 1] += remainder
                total_k = 0
                break
                
            if total_k == 0:
                break
                
        # Step 4: Calculate final sum of squared differences
        ans = 0
        for d, freq in count.items():
            ans += freq * (d ** 2)
            
        return ans