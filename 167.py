def twoSum(numbers, target):
    left, right = 0, len(numbers) - 1

    while left < right:
        s = numbers[left] + numbers[right]
        if s == target:
            return [left + 1, right + 1]
        elif s < target:
            left += 1
        else:
            right -= 1



numbers = list(map(int, input("numbers = ").split()))
target = int(input("target = "))


result = twoSum(numbers, target)
if result:
    n1 = numbers[result[0] - 1]
    n2 = numbers[result[1] - 1]
    print(f"Explanation: The sum of {n1} and {n2} is {target}. "
          f"Therefore index1 = {result[0]}, index2 = {result[1]}. "
          f"We return {result}.")