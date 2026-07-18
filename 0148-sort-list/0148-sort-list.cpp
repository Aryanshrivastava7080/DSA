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
      // Merge two sorted linked lists
    ListNode* merge(ListNode* left, ListNode* right) {

        ListNode dummy(0);
        ListNode* temp = &dummy;

        while (left != NULL && right != NULL) {

            if (left->val <= right->val) {
                temp->next = left;
                left = left->next;
            }
            else {
                temp->next = right;
                right = right->next;
            }

            temp = temp->next;
        }

        if (left != NULL)
            temp->next = left;

        if (right != NULL)
            temp->next = right;

        return dummy.next;
    }

    ListNode* sortList(ListNode* head) {

        // Base Case
        if (head == NULL || head->next == NULL)
            return head;

        // Find Middle
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Split the list
        ListNode* mid = slow->next;
        slow->next = NULL;

        // Sort left & right halves
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);

        // Merge sorted halves
        return merge(left, right);
    }
};