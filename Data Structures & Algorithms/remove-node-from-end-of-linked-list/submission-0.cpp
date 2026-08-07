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
        if(head == nullptr) return head;

        ListNode* temp = head;
        int length = 0;
        while(temp){
            length++;
            temp = temp->next;
        }
        int pos = length - n + 1;
        if(pos == 1){
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        ListNode* curr = head;
        int cnt = 1;
        ListNode* prev = nullptr;
        while(curr != nullptr){
            if(cnt == pos){
                prev->next = curr->next;
                break;
            }
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        return head;
    }
};
