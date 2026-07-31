class Solution {
public:
    int minimumPushes(string word) {
      map<char,int> freq;
        int ans = 0;

      for(char c : word)
      {
        freq[c]++;
      }

      if(freq.size() <= 8)
      {
        return word.length();
      }else
      {
        //sort on basis of freq
        vector<int> arr;
        for(auto itr = freq.begin() ; itr != freq.end() ; itr++)
        {
            arr.push_back(itr->second);
        }

        sort(arr.begin() , arr.end());
        for(int i = 0 ; i < arr.size() ; i++)
        {
          if(i < 8)
          {
            ans += arr[arr.size()-1-i];
          }else if( i < 16)
          {
            ans += 2*arr[arr.size()-1-i];
          }else if(i < 24)
          {
            ans += 3*arr[arr.size()-1-i];
          }else
          {
            ans += 4*arr[arr.size()-1-i];
          }
        }
      }
      return ans;
    }
};