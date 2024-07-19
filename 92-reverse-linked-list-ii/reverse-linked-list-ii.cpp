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
    ListNode* reverse(ListNode* start,ListNode* end){
        ListNode* prev = NULL;
        ListNode* curr = start;

        while(curr != end){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;

        for(int i=0;i<left-1;i++){
            prev = prev->next;
            curr = curr->next;
        }

        ListNode* nextnode = curr;
        for(int i=0;i<right-left+1;i++){
            nextnode = nextnode->next;
        }

        prev->next = reverse(curr,nextnode);
        curr->next = nextnode;
        return dummy->next;
    }
};