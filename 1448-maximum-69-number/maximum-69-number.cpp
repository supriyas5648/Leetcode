class Solution {
public:
    int maximum69Number (int num) {
        
        vector<int> temp ;
        int idx = 0;
        for(int i = num ; i != 0 ; i /= 10)
        {
            temp.push_back(i%10);
        }

        //temp has reverse ordeer
        for(int i = temp.size()-1 ; i >=0 ; i--) 
        {
            if(temp[i] != 9)
            { temp[i] = 9;
              break;
            }
            if(i == 0) return num;//max number hi tha 999
        }

        //now arr to number
        int ans = 0;
        for(int i = temp.size()-1 ; i >=0 ; i-- )
        {
            ans = ans*10 + temp[i];
        }
        return ans;
    }
};