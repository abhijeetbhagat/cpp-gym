/*
 On a N * N grid, we place some 1 * 1 * 1 cubes.

Each value v = grid[i][j] represents a tower of v cubes placed on top of grid cell (i, j).

Return the total surface area of the resulting shapes.

 

Example 1:

Input: [[2]]
Output: 10
Example 2:

Input: [[1,2],[3,4]]
Output: 34
Example 3:

Input: [[1,0],[0,2]]
Output: 16
Example 4:

Input: [[1,1,1],[1,0,1],[1,1,1]]
Output: 32
Example 5:

Input: [[2,2,2],[2,1,2],[2,2,2]]
Output: 46
 */

class Solution {
  public:
    int surfaceArea(vector<vector<int>>& grid) {
      int total = 0;
      for(int i = 0; i < grid.size(); ++i){
        for(int j = 0; j < grid.size(); ++j){ 
          if(grid[i][j] != 0){
            total += grid[i][j] * 6 - (grid[i][j] * 2 - 2);
            //check top, right, bottom, left
            if(i > 0){
              if(grid[i][j] == grid[i-1][j])
                total -= grid[i][j];
              else
                total -= min(grid[i][j], grid[i-1][j]);
            }
            if(j > 0){
              if(grid[i][j] == grid[i][j-1])
                total -= grid[i][j];
              else
                total -= min(grid[i][j], grid[i][j-1]);
            }
            if(i < grid.size()-1){
              if(grid[i][j] == grid[i+1][j])
                total -= grid[i][j];
              else
                total -= min(grid[i][j], grid[i+1][j]); 
            }
            if(j < grid.size()-1){
              if(grid[i][j] == grid[i][j+1])
                total -= grid[i][j];
              else
                total -= min(grid[i][j], grid[i][j+1]); 
            }
          }
        }
      } 
      return total;
    }
};
