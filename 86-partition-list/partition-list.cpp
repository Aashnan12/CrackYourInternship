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
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode(0);
        ListNode* s = small;
        ListNode* large = new ListNode(0);
        ListNode* l = large;

        while(head){
            if(head->val < x){
                s->next = head;
                s = s->next;
            }
            else{
                l->next = head;
                l = l->next;
            }
            head = head->next;
        }
        l->next = NULL;
        s->next = large->next;
        return small->next;
    }
};