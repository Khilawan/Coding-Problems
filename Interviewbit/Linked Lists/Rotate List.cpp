/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:

Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) {

    int num=0;
    ListNode* head=A;
    
    while(head!=NULL){
        head=head->next;
        num++;
    }
    
    B=B%num;

    if(B==0){
        return A;
    }
    
    int i=0;
    B=num-B;
    ListNode* p=A;
    ListNode* q=NULL;
    
    while(i<B){
        q=p;
        p=p->next;
        i++;
    }
    q->next=NULL;
    q=p;
    
    while(p->next!=NULL){
        p=p->next;
    }
    
    p->next=A;
    
    return q;
}
