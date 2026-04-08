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

    ListNode* mergeList(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        if(list1->val > list2->val) swap(list1, list2);
        ListNode* res = list1;
        while(list1 != NULL & list2 != NULL){
            ListNode* temp = NULL;
            while(list1 != NULL && list1->val <= list2->val){
                temp = list1;
                list1 = list1 -> next;
            }
            temp->next = list2;
            swap(list1, list2);
        }
        return res;
    }

    ListNode* findMiddle(ListNode* head){
        ListNode* fast = head -> next;
        ListNode* slow = head;

        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }

    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* middle = findMiddle(head);
        ListNode* leftHead = head;
        ListNode* rightHead = middle->next;
        middle -> next = NULL;
        leftHead = sortList(leftHead);
        rightHead = sortList(rightHead);

        return mergeList(leftHead, rightHead);
   }
};