class Solution:
    def maxSubsequence(self, nums: List[int], k: int) -> List[int]:
        temp = []
        for i in range(len(nums)):
            temp.append([nums[i], i])
        temp.sort(reverse = True)
        s = set()
        for i in range(k):
            s.add(temp[i][1])
        ans = []
        for i in range(len(nums)):
            if i in s:
                ans.append(nums[i])
        return ans