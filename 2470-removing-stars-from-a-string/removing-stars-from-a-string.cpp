class Solution {
public:
    string removeStars(string s) {
        stack<char> st;

        for(char c : s)
        {
            if(c == '*') st.pop();
            else st.push(c);
        }

        string ans = "";
        while(!st.empty())
        {
         ans += st.top();
         st.pop();
        }

        //reverse sting
        for(int i = 0 ; i < ans.length()/2 ; i++)
        {
            char temp = ans[i];
            ans[i] = ans[ans.length()-1-i];
            ans[ans.length()-1-i] = temp;
        }

        return ans;

    }
};