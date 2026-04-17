def smallestRangeII(nums, k):
    nums.sort()
    
    res = nums[-1] - nums[0]
    
    for i in range(len(nums) - 1):
        big = max(nums[i] + k, nums[-1] - k)
        small = min(nums[0] + k, nums[i + 1] - k)
        
        res = min(res, big - small)
    
    return res


nums = list(map(int, input("nums: ").split()))
k = int(input("k: "))

print(smallestRangeII(nums, k))