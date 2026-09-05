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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* t1 = l1;
        ListNode* t2 = l2;

        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;
        while(t1 && t2){
            if(t1->val < t2->val){
                temp->next = t1;
                temp = t1;
                t1=t1->next;
            }else{
                temp->next = t2;
                temp = t2;
                t2=t2->next;
            }
        }
        if(t1) temp->next = t1;
        else temp->next = t2;

        return dummyNode->next;
    }
};
