class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:


        ans = 0

        for i in nums:
            ans^=i
        setbit = 1
        while (ans & setbit) == 0:
            setbit<<=1
        a = 0
        b = 0
        for i in nums:
            if i & setbit:
                a^=i
            else:
                b^=i
        return [a,b]

        