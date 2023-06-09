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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int sum = 0;
        int carry = 0;
        ListNode *dummy = new ListNode();
        ListNode *temp = dummy;
        while((l1 != NULL || l2 != NULL) carry) {
            int sum = 0;
            if(l1 != NULL) {
                sum += l1 -> val; 
                temp = temp->next;
            }
            if(l2 != NULL) {
                sum += l2->val;
                temp = temp->next;
            }

            sum += carry;
            carry = sum / 10;
            ListNode *node = new ListNode(sum % 10);
            temp -> next = node;
            temp = temp->next;

        }
        return dummy -> next;
    }
};