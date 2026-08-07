class Solution:
    def hammingWeight(self, n: int) -> int:

        k = n.bit_length()
        m = 0

        for i in range(k):
            if (n >> i) & 1:
                m += 1

        return m