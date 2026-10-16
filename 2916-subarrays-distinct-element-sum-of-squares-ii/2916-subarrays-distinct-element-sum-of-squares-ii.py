class SegmentTree:
    def __init__(self, n):
        self.n = n
        self.sum_d = [0] * (4 * n)
        self.sum_sq = [0] * (4 * n)
        self.lazy = [0] * (4 * n)

    def _push(self, node, l, r):
        if self.lazy[node] != 0:
            val = self.lazy[node]
            mid = (l + r) // 2
            
            # Left child update
            left_len = mid - l + 1
            self.sum_sq[2 * node] = (self.sum_sq[2 * node] + 2 * val * self.sum_d[2 * node] + val * val * left_len) % 1000000007
            self.sum_d[2 * node] = (self.sum_d[2 * node] + val * left_len) % 1000000007
            self.lazy[2 * node] += val

            # Right child update
            right_len = r - mid
            self.sum_sq[2 * node + 1] = (self.sum_sq[2 * node + 1] + 2 * val * self.sum_d[2 * node + 1] + val * val * right_len) % 1000000007
            self.sum_d[2 * node + 1] = (self.sum_d[2 * node + 1] + val * right_len) % 1000000007
            self.lazy[2 * node + 1] += val

            self.lazy[node] = 0

    def update(self, node, l, r, ql, qr, val):
        if ql <= l and r <= qr:
            length = r - l + 1
            self.sum_sq[node] = (self.sum_sq[node] + 2 * val * self.sum_d[node] + val * val * length) % 1000000007
            self.sum_d[node] = (self.sum_d[node] + val * length) % 1000000007
            self.lazy[node] += val
            return

        self._push(node, l, r)
        mid = (l + r) // 2
        if ql <= mid:
            self.update(2 * node, l, mid, ql, qr, val)
        if qr > mid:
            self.update(2 * node + 1, mid + 1, r, ql, qr, val)

        self.sum_d[node] = (self.sum_d[2 * node] + self.sum_d[2 * node + 1]) % 1000000007
        self.sum_sq[node] = (self.sum_sq[2 * node] + self.sum_sq[2 * node + 1]) % 1000000007

class Solution:
    def sumCounts(self, nums: List[int]) -> int:
        MOD = 10**9 + 7
        n = len(nums)
        tree = SegmentTree(n)
        last_pos = {}
        total_sum = 0

        for i, val in enumerate(nums):
            prev = last_pos.get(val, -1)
            # Range [prev + 1, i] par +1 add karo
            tree.update(1, 0, n - 1, prev + 1, i, 1)
            
            # Root node par abhi tak ke saare ending-at-i subarrays ke squares ka sum hai
            total_sum = (total_sum + tree.sum_sq[1]) % MOD
            last_pos[val] = i

        return total_sum