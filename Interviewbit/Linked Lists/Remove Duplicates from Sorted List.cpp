/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode* prev=A;
    ListNode* head=A;
    
    if(head==NULL||head->next==NULL){
        return head;
    }
    head=head->next;
    while(head!=NULL){
        if(prev->val==head->val){
            head=head->next;
        }else{
            prev->next=head;
            prev=head;
            head=head->next;
        }
    }
    prev->next=NULL;
    return A;
}
