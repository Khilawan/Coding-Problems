/*
You are given with an array of 1s and 0s. And you are given with an integer M, which signifies number of flips allowed.
Find the position of zeros which when flipped will produce maximum continuous series of 1s.

For this problem, return the indices of maximum continuous series of 1s in order.

Example:

Input : 
Array = {1 1 0 1 1 0 0 1 1 1 } 
M = 1

Output : 
[0, 1, 2, 3, 4] 

If there are multiple possible solutions, return the sequence which has the minimum start index.
*/

vector<int> Solution::maxone(vector<int> &A, int B) {
    int ml=0,mr=0,l=0,r=0;
    int max=0;
    int count=0;
    while(r<A.size()&&l<A.size()){
        if(A[r]==0){
            count++;
            if(count>B){
                int tmp=r-l-1;
                if(tmp>max){
                    max=tmp;
                    ml=l;
                    mr=r-1;
                }
                while(A[l]!=0){
                    l++;
                }
                count--;
                l++;
            }
        }
        r++;
    }
    if(r-l-1>max){
        ml=l;
        mr=r-1;
    }
    vector<int>c;
    for(int i=ml;i<=mr;i++){
        c.push_back(i);
    }
    return c;
}
