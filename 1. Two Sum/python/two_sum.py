class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        solution = 0
        for i in range(len(nums)):
            for j in range(len(nums)):
                if i != j:
                    solution = nums[i]+nums[j]
                    if solution == target:
                        solutions = [i, j]
                        return solutions