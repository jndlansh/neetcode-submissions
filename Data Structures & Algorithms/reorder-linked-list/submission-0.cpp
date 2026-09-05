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
        if(head==NULL) return;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next!=NULL and fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondList = slow->next;
        slow->next = NULL;

        ListNode* curr = secondList;
        ListNode* prev = NULL;

        while(curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        secondList = prev;

        ListNode* t1 = head;
        ListNode* t2 = secondList;

        while(t1 && t2){
            ListNode* n1 = t1->next;
            ListNode* n2 = t2->next;

            t1->next = t2;
            t2->next = n1;

            t1=n1;
            t2=n2;
        }
    }
};
