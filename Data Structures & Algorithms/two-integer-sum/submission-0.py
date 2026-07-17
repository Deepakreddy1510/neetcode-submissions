class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mpp = {}
        for i in range(len(nums)):
            if target - nums[i] in mpp:
                if i < mpp[target-nums[i]]:
                    return [i, mpp[target-nums[i]]]
                else:
                    return [mpp[target-nums[i]], i]
            mpp[nums[i]] = i