class Solution:
    def countBits(self, n: int) -> List[int]:

        result = []

        for i in range(n + 1):
            count = 0
            num = i

            while num > 0:
                count += num & 1
                num >>= 1

            result.append(count)

        return result