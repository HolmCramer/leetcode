class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        solution = 0
        for i in range(len(nums)):
            for j in range(len(nums)):
                if i != j:
                    solution = nums[i]+nums[j]
                    if solution == target:
                        solutions = [i, j]
                        return solutions