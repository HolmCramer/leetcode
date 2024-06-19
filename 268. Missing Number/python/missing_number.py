class Solution:
    def missingNumber(self, nums: list[int]) -> int:
        nums.sort()

        n = 0
        while n == nums[n]:
            n += 1
            if n > len(nums)-1:
                break
        return n