/*
Merge k sorted linked lists and return it as one sorted list.

Example :

1 -> 10 -> 20
4 -> 11 -> 13
3 -> 8 -> 9
will result in

1 -> 3 -> 4 -> 8 -> 9 -> 10 -> 11 -> 13 -> 20

*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    
    ListNode* node=new ListNode(0);
    ListNode* head=node;
    
    priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>>>q;
    
    for(int i=0;i<A.size();i++){
        q.push(make_pair(A[i]->val,A[i]));
    }
    
    while(!q.empty()){
        head->next=q.top().second;
        head=q.top().second;
        q.pop();
        if(head->next!=NULL){
            q.push(make_pair(head->next->val,head->next));
        }
    }
    
    return node->next;
}
