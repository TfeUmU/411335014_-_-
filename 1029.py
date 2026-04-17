import ast

class Solution:
    def twoCitySchedCost(self, costs):
        n = len(costs) // 2
        costs.sort(key=lambda x: x[1] - x[0])
        total = 0
        for i in range(n):
            total += costs[i][1]
        for i in range(n, 2 * n):
            total += costs[i][0]
        return total

# 輸入範例：costs = [[10,20],[30,200],[400,50],[30,20]]
user_input = input("Input: costs = ")

costs = ast.literal_eval(user_input)

sol = Solution()
result = sol.twoCitySchedCost(costs)
print("Output:", result)