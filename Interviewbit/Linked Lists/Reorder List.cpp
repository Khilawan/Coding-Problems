/*
Given a singly linked list

    L: L0 → L1 → … → Ln-1 → Ln,
reorder it to:

    L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …
You must do this in-place without altering the nodes’ values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* reverse(ListNode* A){
    ListNode* head=A;
    
    if(head==NULL||head->next==NULL){
        return head;
    }
    ListNode* p=NULL;
    ListNode* q=head;
    
    
    ListNode* tmp=NULL;
    while(q->next!=NULL){
        tmp=q->next;
        q->next=p;
        p=q;
        q=tmp;
    }
    q->next=p;
    head=q;
    
    return head;
}
 
ListNode* Solution::reorderList(ListNode* A) {
    
    if(A==NULL||A->next==NULL){
        return A;
    }
    
    int i=0;
    ListNode* p=A;
    ListNode* q=A;
    ListNode* head=A;
    
    while(p!=NULL){
        i++;
        p=p->next;
    }
    
    i=i/2;
    p=A;
    
    int j=0;
    while(j<i){
        p=p->next;
        j++;
    }
    
    q=p->next;
    p->next=NULL;
    
    q=reverse(q);
    ListNode* t1=p;
    ListNode* t2=q;
    p=A;

    while(p!=NULL&&q!=NULL){
        t1=p->next;
        p->next=q;
        p=t1;
        t2=q->next;
        q->next=p;
        q=t2;
    }
    
    return head;
    
}
