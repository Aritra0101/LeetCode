# class Solution:
#     def onesMinusZeros(self, grid: List[List[int]]) -> List[List[int]]:
        

class Solution:
  def onesMinusZeros(self, grid: List[List[int]]) -> List[List[int]]:
    m = len(grid)
    n = len(grid[0])
    ans = [[0] * n for _ in range(m)]
    onesRow = [row.count(1) for row in grid]
    onesCol = [col.count(1) for col in zip(*grid)]

    for i in range(m):
      for j in range(n):
        ans[i][j] = onesRow[i] + onesCol[j] - \
            (n - onesRow[i]) - (m - onesCol[j])

    return ans