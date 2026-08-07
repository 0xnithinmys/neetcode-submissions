class Solution:
    def addBinary(self, a: str, b: str) -> str:
        n1 = len(a) - 1
        n2 = len(b) - 1
        carry = 0
        result = ""

        while n1 >= 0 or n2 >= 0 or carry:

            bit1 = int(a[n1]) if n1 >= 0 else 0
            bit2 = int(b[n2]) if n2 >= 0 else 0

            total = bit1 + bit2 + carry

            result = str(total % 2) + result
            carry = total // 2

            n1 -= 1
            n2 -= 1

        return result
