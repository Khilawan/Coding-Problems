/*
Merge two sorted linked lists and return it as a new list.
The new list should be made by splicing together the nodes of the first two lists, and should also be sorted.

For example, given following linked lists :

  5 -> 8 -> 20 
  4 -> 11 -> 15

  
The merged list should be :

4 -> 5 -> 8 -> 11 -> 15 -> 20

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode* head=NULL;
    ListNode* res=NULL;
    
    if(A==NULL){
        return B;
    }else if(B==NULL){
        return A;
    }
    
    if(A->val<B->val){
        head=A;
        A=A->next;
        res=head;
    }else{
        head=B;
        B=B->next;
        res=head;
    }
    
    while(A!=NULL&&B!=NULL){
        if(A->val<B->val){
            head->next=A;
            head=A;
            A=A->next;
        }else{
            head->next=B;
            head=B;
            B=B->next;
        }   
    }
    
    while(A!=NULL){
        head->next=A;
        head=A;
        A=A->next;
    }
    
    while(B!=NULL){
        head->next=B;
        head=B;
        B=B->next;
    }
    
    return res;
}
