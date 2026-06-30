class Solution {
public:
    int compress(vector<char>& chars) {
        int grp_len = 1 ;
        char curr_char = chars[0];
        vector<char> ans;

        for(int i =1 ; i < chars.size() ; i++)
        {
           if(chars[i] == curr_char) grp_len++;
           else
           {
             ans.push_back(curr_char);
             if(grp_len == 1);
             else if(grp_len < 10) ans.push_back('0' +grp_len);
             else
             {
                string s = to_string(grp_len);
                for(int i = 0 ; i < s.length() ; i++)
                {
                    ans.push_back(s[i]);
                }
             }
             curr_char = chars[i];
             grp_len = 1;
             
           }
        }

        //last elem
        if(grp_len >= 1)
        {
            ans.push_back(curr_char);
            if(grp_len == 1);
             else if(grp_len < 10) ans.push_back('0' + grp_len);
             else
             {
                string s =to_string(grp_len);
                for(int i = 0 ; i < s.length() ; i++)
                {
                    ans.push_back(s[i]);
                }
             }
        }

        //ans to chars
        for(int i = 0 ; i < min(ans.size(),chars.size()) ; i++)
        {
            chars[i] = ans[i];
        }

        return ans.size();
    } 
};