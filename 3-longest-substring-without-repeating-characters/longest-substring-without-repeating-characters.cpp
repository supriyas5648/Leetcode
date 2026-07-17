class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       map<char,int> mp; // char-> first idx
       int ans = 0;
       int start = 0;

       for(int end = 0 ; end < s.length() ; end++)
       {
         if(mp.count(s[end]) && mp[s[end]] >= start) //elem exists
         {
             start = mp[s[end]]+1;
             mp[s[end]] = end;     
         }
         else mp[s[end]] = end;

         ans = max(ans,end-start+1);
       }  
       return ans;
    }
};