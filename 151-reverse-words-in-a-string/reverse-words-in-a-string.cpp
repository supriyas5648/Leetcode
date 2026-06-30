class Solution {
public:
    string reverseWords(string s) {
      vector<string> arr;

      //strings  in arr
      for(int i = 0 ; i < s.length() ; i++)
      {
        string str = "";
        while(i < s.length() && s[i] != ' ')
        {
          str += s[i]; 
          i++;
        }
        if(str != "") arr.push_back(str);
      }  

      string res = "";
      //now take arr elem in reverse order
      for(int i = arr.size()-1 ; i >= 0 ; i--)
      {
        res += arr[i];
        res = (i > 0)? res+ " " : res; //akhiri me space na aaye
      }
      return res;
    }
};