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
        ListNode* temp = head;
        int cnt = 0;
        if(head ==NULL)
            return head;
        while(temp != NULL){
            temp = temp->next;
            cnt++;
        }
        
        if(cnt == n){
            return head->next;
        }
        else{
            int i=1;
             for(temp = head; i < cnt - n; i++)
             {
              temp= temp->next;
             }
             temp->next=temp->next->next;
        }
        return head;
    }
};