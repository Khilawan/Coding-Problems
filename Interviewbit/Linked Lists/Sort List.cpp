/*
Sort a linked list in O(n log n) time using constant space complexity.

Example :

Input : 1 -> 5 -> 4 -> 3

Returned list : 1 -> 3 -> 4 -> 5
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 
ListNode* merge(ListNode* A, ListNode* mid){

    ListNode* a=A;
    ListNode* b=mid;
    ListNode* p=NULL;
    ListNode* merged=NULL;
    
    while(a!=NULL&&b!=NULL){
        ListNode* tmp=NULL;
        
        if(a->val<b->val){
            tmp=a;
            a=a->next;
        }else{
            tmp=b;
            b=b->next;
        }
        
        if(merged){
            p->next=tmp;
            p=tmp;
        }else{
            merged=tmp;
            p=tmp;
        }
    }
    
    while(a!=NULL){
        p->next=a;
        p=a;
        a=a->next;
    }
    while(b!=NULL){
        p->next=b;
        p=b;
        b=b->next;
    }
    
    if(p!=NULL){
        p->next=NULL;    
    }
    
    return merged;
}


void mergesort(ListNode*& A){

    if(A==NULL||A->next==NULL){
        return;
    }
    
    ListNode* prev=NULL;
    ListNode* fast=A;
    ListNode* mid=A;
    
    while(fast!=NULL&&fast->next!=NULL){
        prev=mid;
        mid=mid->next;
        fast=fast->next->next;
    }
    
    if(prev){
        prev->next = NULL;
    }
    
    mergesort(A);
    mergesort(mid);

    A=merge(A,mid);
}


 
ListNode* Solution::sortList(ListNode* A) {
    
    mergesort(A);
    return A;
}

