import random

def findKthLargest(nums, k):
    lo, hi = 0, len(nums) - 1
    target = len(nums) - k

    while True:
        rand_i = random.randint(lo, hi)
        final_i = partition(nums, lo, hi, rand_i)

        if final_i == target:
            return nums[final_i]
        elif final_i > target:
            hi = final_i - 1
        else:
            lo = final_i + 1

def partition(nums, lo, hi, pivot_i):
    pivot = nums[pivot_i]

    nums[pivot_i], nums[hi] = nums[hi], nums[pivot_i]

    store = lo
    for i in range(lo, hi):
        if nums[i] < pivot:
            nums[i], nums[store] = nums[store], nums[i]
            store += 1

    nums[store], nums[hi] = nums[hi], nums[store]
    return store


raw = input("Enter numbers : ")
nums = list(map(int, raw.split()))

k = int(input(f"Enter k : "))

result = findKthLargest(nums[:], k)
print(f"The {k}th largest number is: {result}")