class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        ans = [0] * len(nums)
        pos=0
        neg=1
        for i in range(len(nums)):
            if nums[i]<0:
                ans[neg]=nums[i]
                neg=neg+2
            else:
                ans[pos]=nums[i]
                pos=pos+2
        return ans