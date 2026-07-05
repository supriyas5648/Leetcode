class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
      int n = grid.size();
      vector<int> row_sum(n,0);
      vector<int> colm_sum(n,0);

      //colm sum and row sum
      for(int i =0 ; i < n ; i++) //going top to bttm
      {
        for(int j = 0 ; j < n ; j++)
        {
            row_sum[i] += grid[i][j];
            colm_sum[j] += grid[i][j];
        }
      } 

      //now each row with colm comapre
      int count = 0;
      for(int r = 0 ; r < n ; r++)
      {
        for(int c = 0 ; c < n ; c++ )
        {
            if(colm_sum[c] == row_sum[r])
            {
                //check for elem
                for(int k = 0 ; k < n ; k++)
                {
                  if(grid[r][k] != grid[k][c]) break;

                  if(k == n-1) count++;
                }
            }
        }
      } 
      return count; 
    }
};