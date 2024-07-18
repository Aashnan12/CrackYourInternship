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
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode* connect = NULL;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            connect = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        connect->next = NULL;

        ListNode* prev = NULL;
        ListNode* curr = slow;
        while(curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        curr = head;
        ListNode* nextnode = NULL;
        while(prev){
            nextnode = curr->next;
            curr->next = prev;
            curr = prev;
            prev = nextnode;
        }

    }
};