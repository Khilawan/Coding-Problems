/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

    342 + 465 = 807
Make sure there are no trailing zeros in the output list
So, 7 -> 0 -> 8 -> 0 is not a valid response even though the value is still 807.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    if(A==NULL){
        return B;
    }else if(B==NULL){
        return A;
    }
    
    ListNode* p=A;
    ListNode* q=B;
    ListNode* node=new ListNode(0);
    ListNode* head=node;
    ListNode* prev=NULL;
    
    if(A==NULL){
        return B;
    }else if(B==NULL){
        return A;
    }
    
    int carry=0;
    
    while(p!=NULL&&q!=NULL){
        carry+=p->val+q->val;
        head->val=carry%10;
        ListNode* newnode=new ListNode(0);
        prev=head;
        head->next=newnode;
        head=newnode;
        carry/=10;
        p=p->next;
        q=q->next;
    }
    
    while(p!=NULL){
        carry+=p->val;
        head->val=carry%10;
        ListNode* newnode=new ListNode(0);
        prev=head;
        head->next=newnode;
        head=newnode;
        carry/=10;
        p=p->next;
    }
    while(q!=NULL){
        carry+=q->val;
        head->val=carry%10;
        ListNode* newnode=new ListNode(0);
        prev=head;
        head->next=newnode;
        head=newnode;
        carry/=10;
        q=q->next;
    }
    
    if(carry!=0){
        head->val=carry;
    }
    
    if(head->val==0){
        prev->next=NULL;
    }
    
    return node;
}
