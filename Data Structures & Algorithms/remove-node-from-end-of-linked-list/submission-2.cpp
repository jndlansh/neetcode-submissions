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
        if(!head or !head->next) return NULL;

        int cnt=0;
        ListNode* temp = head;
        while(temp){
            temp = temp->next;
            cnt++;
        }

        if(n == cnt) return head->next;

        int len=cnt-n-1;
        temp = head;

        for(int i=0; i<len; i++){
            temp = temp->next;
        }

        ListNode* curr = temp->next;
        temp->next = temp->next->next;
        curr->next = NULL;
        // delete(curr);

        return head;
    }
};
