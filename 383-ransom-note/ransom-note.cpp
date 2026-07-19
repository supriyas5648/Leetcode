class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
       unordered_map<char,int> mp1;
       unordered_map<char,int> mp2;

       for(char c: ransomNote)
       {
        mp1[c]++;
       } 

       for(char c : magazine)
       {
        mp2[c]++;
       }

       for(auto itr = mp1.begin() ; itr != mp1.end() ; itr++)
       {
         if(mp2.count(itr->first) == false) return false;
         else if(mp2[itr->first] < itr->second) return false;
       }

       return true;
    }
};