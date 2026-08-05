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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* left = list1;
        ListNode* right = list2;
        ListNode* curr = dummy;

        while(left && right){
            if(left->val <= right->val){
                curr->next = left;
                left = left->next;
            }
            else{
                curr->next = right;
                right = right->next;
            }
            curr = curr->next;
        }

        if(left){
            curr->next = left;
        }
        else{
            curr->next = right;
        }

        return dummy->next;
    }
};
