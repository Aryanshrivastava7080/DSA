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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
         // Dummy node banaya
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Fast ko n+1 steps aage le jao
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // Dono pointers ko saath chalao
        while (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        // Node delete karo
        slow->next = slow->next->next;

        return dummy->next;
    }
};