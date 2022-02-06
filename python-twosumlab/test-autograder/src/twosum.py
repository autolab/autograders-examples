def two_sum(nums, target):
  hist = {}

  for i in range(len(nums)):
    if target - nums[i] in hist:
      return [hist[target - nums[i]], i]
    else:
      hist[nums[i]] = i

  return []

# brute force
# def two_sum(nums, target):
#     for i, a in enumerate(nums, start=0):
#         for j, b in enumerate(nums[i+1:], start=0):
#             if a+b==target:
#                 return [i, j+i+1]

# invalid naive solution
# def two_sum(nums, target):
#   return [0, 1]