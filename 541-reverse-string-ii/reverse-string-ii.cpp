class Solution {
public:
    void reverse(int start,int end, string& s)
    {
        while(start < end)
        {
            char temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            start++;
            end--;
        }
    }
    string reverseStr(string s, int k) {
        int j = 0; //track start of window
        int count = 0;

        if(s.length() < k) reverse(0,s.length()-1,s);
        
        for(int i = 0 ; i < s.length() ; i++)
        {
            count++;
            if(count == k) reverse(j,j+k-1,s);
            if(count == 2*k)
            {
                 j = j + 2*k;
                 count = 0;

                 if(j+k > s.length()) reverse(j,s.length()-1,s);;
            }
        }
        return s;
    }
};