class Solution {
public:
    bool freq_match(map<char,int>& mp1 , map<char,int>& mp2)
    {
      if(mp1.size() != mp2.size()) return false;

      for(auto itr = mp1.begin(); itr != mp1.end(); itr++)
      {
        //does that elem exist
        if(!mp2.count(itr->first)) return false;

        //freq same
        if(itr->second != mp2[itr->first]) return false;
      }
      return true;
    }

    map<char,int> freqmap(string& s)
    {
        map<char,int> freq;

        for(char c : s)
        {
            freq[c]++;
        }
        return freq;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       //make freq mapping of each
       vector<map<char,int>> mp_arr;

       for(int i = 0 ; i < strs.size() ; i++)
       {
         mp_arr.push_back(freqmap(strs[i]));
       }

       vector<vector<string>> ans;
       //to avoid manipulating actual string
       vector<string> temp = strs;
       for(int i = 0 ; i < temp.size() ; i++)
       {
         if(temp[i] == "X") continue;
         else 
         {
             ans.push_back({temp[i]});
             for(int j = i+1; j <temp.size() ; j++)
             {
               if(temp[j] == "X") continue;//that is booked

               //check anagram
               if(freq_match(mp_arr[i],mp_arr[j]))
               {
                ans[ans.size()-1].push_back(temp[j]);
                temp[j] = "X"; //used
               }
             }
           }
        }
      return ans;
    }
};