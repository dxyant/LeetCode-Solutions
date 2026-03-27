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
    ListNode* intersection(ListNode *t1,ListNode *t2, int d){
        while(d-- && t1 != NULL){
            t1 = t1->next;
        }
        while(t1 != t2 && t1 != NULL && t2 != NULL){
            t1 = t1->next;
            t2 = t2->next;
        }
        return t1;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        int n1 = 0, n2 = 0;
        while(temp1 != NULL){
            n1++;
            temp1 = temp1 -> next;
        }
        while(temp2 != NULL){
            n2++;
            temp2 = temp2 -> next;
        }
        if(n2 < n1) {
            return intersection(headA, headB, n1-n2);
        } else {
            return intersection(headB, headA, n2-n1);
        }
        return NULL;
    }
};