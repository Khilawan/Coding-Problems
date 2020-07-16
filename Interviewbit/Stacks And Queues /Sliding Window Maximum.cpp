/*
Given an array of integers A. There is a sliding window of size B which
is moving from the very left of the array to the very right.
You can only see the w numbers in the window. Each time the sliding window moves
rightwards by one position. You have to find the maximum for each window.

Return an array C, where C[i] is the maximum value of from A[i] to A[i+B-1].

Note: If B > length of the array, return 1 element with the max of the array.



Input Format

The first argument given is the integer array A.
The second argument given is the integer B.


Output Format

Return an array C, where C[i] is the maximum value of from A[i] to A[i+B-1]


For Example

Input 1:
    A = [1, 3, -1, -3, 5, 3, 6, 7]
    B = 3
Output 1:
    C = [3, 3, 5, 5, 6, 7]


*/

struct qq{
    int val;
    int ind;
};

vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    
    vector<int>v;
    deque<qq>q;
    qq max;
    
    for(int i=0;i<B;i++){
        if(q.empty()){
            qq num;
            num.val=A[i];
            num.ind=i;
            q.push_back(num);
        }else{
            while(!q.empty()&&q.back().val<A[i]){
                q.pop_back();
            }
            qq vv;
            vv.val=A[i];
            vv.ind=i;
            q.push_back(vv);
        }
        
    }
    
    v.push_back(q.front().val);
    int n=A.size();
    
    for(int i=B;i<n;i++){
        if(q.front().ind<=i-B){
            q.pop_front();
        }
        while(!q.empty()&&q.back().val<A[i]){
            q.pop_back();
        }
        
        qq num;
        num.val=A[i];
        num.ind=i;
        q.push_back(num);
        
        v.push_back(q.front().val);
        
    }

    return v;
}
