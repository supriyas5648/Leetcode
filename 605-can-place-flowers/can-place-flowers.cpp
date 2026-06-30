class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int left ;int right;

        for(int i = 0 ; i < flowerbed.size() ; i++)
        {
          left =(i > 0)?i-1 : -1;
          right= (i < flowerbed.size()-1)? i+1 : -1;

          //left khali..right khali ---so place there
          if(flowerbed[i] == 0 &&
            (left == -1 ||flowerbed[left] == 0) && 
            (right == -1 || flowerbed[right] == 0 ))
             {
                n--;
                flowerbed[i] = 1;
                if( n == 0 ) return true;
             }
          
        }

        if( n <= 0) return true;
        return false;
    }
};