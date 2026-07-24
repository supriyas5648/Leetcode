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
    ListNode* swapPairs(ListNode* head) {

       ListNode* curr = head;
       ListNode* prev1 = nullptr;
       ListNode* prev2;
       ListNode* temp;
       int count = 0;
       
       while(curr != nullptr)
       {
         count++;

         if(count%2 == 0)
         {
           if(prev1 == nullptr) 
           {
            //initial one
            temp = curr->next;
            curr->next = prev2;
            prev2->next = temp;

            head = curr;
            curr = prev2;
            prev1 = curr;
           }else
           {
            temp = curr->next; //4->next
            prev1->next = curr; //2->4
            curr->next = prev2; //2->4->3
            prev2->next = temp; //2->4->3->temp

            curr = prev2 ;
            prev1 = curr;
           }
        }else
        {
            prev2 = curr;
        }

        curr = curr->next;
       }

       return head;
    }
};