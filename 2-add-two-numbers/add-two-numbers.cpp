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
    ListNode* addTwoNumbers(ListNode* A, ListNode* B) {
        ListNode* dummy = new ListNode(0);
        ListNode*curr = dummy;
        int sum = 0,carry = 0;

        while(A != NULL || B != NULL || carry){
            if(A != NULL){
                sum += A->val;
                A = A->next;
            }
            if(B != NULL){
                sum += B->val;
                B = B->next;
            }
            sum += carry;
            curr->next = new ListNode(sum%10);
            curr = curr->next;
            carry = sum/10;
            sum = 0;
        }
        return dummy->next;
    }
};