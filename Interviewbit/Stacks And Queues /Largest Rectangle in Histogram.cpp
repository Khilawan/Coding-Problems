/*
Given an array of integers A of size N. A represents a histogram i.e A[i] denotes height of
the ith histogram’s bar. Width of each bar is 1.

Find the area of largest rectangle in the histogram.



Input Format

The only argument given is the integer array A.


Output Format

Return the area of largest rectangle in the histogram.


For Example

Input 1:
    A = [2, 1, 5, 6, 2, 3]
Output 1:
    10
    Explanation 1:
        The largest rectangle is shown in the shaded area, which has area = 10 unit.
*/

int Solution::largestRectangleArea(vector<int> &A) {
    int n=A.size();
    vector<int> l(n);
    vector<int> r(n);
    
    stack<int>s;
    
    for(int i=0;i<n;i++){
        if(s.empty()){
            l[i]=i;
        }else if(!s.empty()&&A[s.top()]>=A[i]){
            int prev=i;
            while(!s.empty()&&A[s.top()]>=A[i]){
                prev=l[s.top()];
                s.pop();
            }
            l[i]=l[prev];
        }else if(!s.empty()&&A[s.top()]<A[i]){
            l[i]=i;
        }
        
        s.push(i);
    }
    
    while(!s.empty()){
        s.pop();
    }
    
    for(int i=n-1;i>=0;i--){
        if(s.empty()){
            r[i]=i;
        }else if(!s.empty()&&A[s.top()]>=A[i]){
            int prev=i;
            while(!s.empty()&&A[s.top()]>=A[i]){
                
                prev=r[s.top()];
                s.pop();
            }
            r[i]=r[prev];
        }else if(!s.empty()&&A[s.top()]<A[i]){
            r[i]=i;
        }
        
        s.push(i);
    }
    
    int max=0;
    int tmp=0;
    for(int i=0;i<n;i++){
        tmp=(r[i]-l[i]+1)*A[i];
        
        if(tmp>max){
            max=tmp;
        }
    }
    
    
    return max;
}
