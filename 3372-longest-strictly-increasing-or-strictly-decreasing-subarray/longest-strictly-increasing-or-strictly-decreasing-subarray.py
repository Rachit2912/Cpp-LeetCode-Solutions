class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:
        maxl = 1
        l = 1
        for i in range(1, len(nums)):
            if nums[i] > nums[i-1]:
                l += 1
            else:
                l = 1
            maxl = max(maxl, l)
        minl = 1
        l = 1
        for i in range(1, len(nums)):
            if nums[i] < nums[i-1]:
                l += 1
            else:
                l = 1
            minl = max(minl, l)

        # print(maxl, minl)
        return max(maxl, minl)