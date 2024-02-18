def maxsubarray(nums):
    n = len(nums)
    if n == 1:
        return nums[0]
    lookup = [0] * n
    lookup[0] = nums[0]
    res = nums[0]
    for i in range(1, n):
        lookup[i] = max(lookup[i-1]+nums[i], nums[i])
        res = max(res, lookup[i])
    return res