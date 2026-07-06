/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

      int idx = 1;

      ListNode* odd = new ListNode(0);
      ListNode* even_head = new ListNode(0);
      ListNode* even = even_head;

      ListNode* curr = head;

      while(curr != nullptr)
      {
        if(idx%2 == 0)
        {
          //odd mese isko nikal do
          odd->next = curr->next; 

          //curr ko even me add kro
          curr->next = nullptr; 
          even->next = curr;
          even = even->next;

          curr = odd->next;      
        }else
        {
            odd = curr;
            curr = curr->next;
        }
        idx++;
      }

      //combine them
        odd->next = even_head->next;
        return head;
    }
};