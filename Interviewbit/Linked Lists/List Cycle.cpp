/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Try solving it using constant additional space.

Example :

Input : 

                  ______
                 |     |
                 \/    |
        1 -> 2 -> 3 -> 4

Return the node corresponding to node 3. 
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    
    if(A==NULL||A->next==NULL){
        return NULL;
    }
    
    ListNode* slow=A;
    ListNode* fast=A;
    int flag=0;
    
    while(slow!=NULL&&fast!=NULL&&fast->next!=NULL){
        
        slow=slow->next;
        fast=fast->next->next;
        
        if(slow==fast){
            flag=1;
            break;
        }
        
    }
    
    if(flag==1){
        slow=A;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
    
    return NULL;
}
