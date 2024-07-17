/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *A, ListNode *B) {
        unordered_map<ListNode*,int> map;

        for(ListNode* i = A; i != NULL ; i = i->next){
            map[i] = i->val;
        }

        for(ListNode* i = B; i != NULL ; i = i->next){
            if(map.find(i) != map.end()){
                return i;
            }
        }
        return NULL;
    }
};