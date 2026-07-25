class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
       vector<vector<int>> arr(n,vector<int>(n,-1));
       if(n == 1) return {{1}};
     
      int loop = (n+1)/2;
      int num = 1;
      for(int k = 1 ; k <= loop ; k++ )
      {
        int i = k-1;
        int j = k-1;
        
        //->..+..j
        while(j <= n-k)
        {
          arr[i][j] = num;
          num++;
           j++;
        }

        //+...i
        j--;
        i = i+1;
        if(arr[i][j] != -1) return arr; //n= odd end reached
        while(i <= n-k )
        {
              arr[i][j] = num;
              num++; 
              i++;
        }

        //-..j
        i--;
        j = j-1;
        while(j >= k-1)
        {
           arr[i][j] = num;
           num++;  
            j-- ;
        }

        //-..i 
        j++;
        i = i-1;
        if(arr[i][j] != -1) return arr; // n = even end reached
        else
        {
          while(i >= k )
          {
           arr[i][j] = num;
           num++;  
            i--;
          }  
        }

      } 

      return  arr;
    }
};