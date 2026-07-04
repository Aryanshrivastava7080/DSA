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
    ListNode* deleteDuplicates(ListNode* head) {
//         ListNode*newNode=new ListNode(0);
//         newNode->next=head;
//         ListNode*prev = newNode;
//         ListNode*curr=head;
       

//         while(curr!=NULL){
            
//             if(curr->next!=NULL && curr->val == curr->next->val){

//                 while(curr!=NULL && curr->val == curr->next->val){
//                     curr = curr->next;
//                 }
//                 prev->next = curr->next;
//             }
//             else{
//                 prev = prev->next;
//             }
//              curr = curr->next;
//         }
//         return newNode->next;   
//     }
// };
  ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr != NULL) {

            // Duplicate mila
            if (curr->next != NULL && curr->val == curr->next->val) {

                // Last duplicate tak jao
                while (curr->next != NULL && curr->val == curr->next->val) {
                    curr = curr->next;
                }

                // Saare duplicate skip
                prev->next = curr->next;
            }
            else {
                // Unique node
                prev = prev->next;
            }

            curr = curr->next;
        }

        return dummy->next;
    }
};