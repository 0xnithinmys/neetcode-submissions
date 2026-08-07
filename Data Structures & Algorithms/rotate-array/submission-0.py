class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        nums.reverse()
        k = k%len(nums)

        nums[:k]= reversed(nums[:k])

        nums[k:]=  reversed(nums[k:])
        



         


        