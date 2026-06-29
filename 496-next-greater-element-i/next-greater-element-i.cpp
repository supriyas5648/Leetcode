class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

    //map for idx storing
     map<int,int> mp; //elem->idx

     //next greater of num2
     stack<int> st;
     vector<int> temp(nums2.size(),-1);
     st.push(nums2[nums2.size()-1]);//last elem in stack
     mp.insert({nums2[nums2.size()-1],nums2.size()-1}); //last elem in mp

     for(int i = nums2.size()-2 ; i >= 0 ; i--)
     {
        mp.insert({nums2[i],i});//elem->idx

        //jab tak top chota h nikalte jao
        while(!st.empty() && nums2[i] >= st.top()) st.pop();

        //top > curr_elem
        if(!st.empty() && nums2[i] < st.top())
        {
            temp[i] = st.top();
            st.push(nums2[i]); //ye kisi ka next greater ho skta
        }else
        {
            st.push(nums2[i]);
        }
     }   

     //now mapping answer
     vector<int> ans(nums1.size());
     for(int i =0 ; i < nums1.size() ; i++)
     {
       ans[i] = temp[mp[nums1[i]]];
     }
    
    return ans;
    }
};