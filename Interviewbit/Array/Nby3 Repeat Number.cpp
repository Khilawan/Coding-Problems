/*
You’re given a read only array of n integers. Find out if any integer occurs more than n/3 times in the array in linear time and constant additional space.

If so, return the integer. If not, return -1.

If there are multiple solutions, return any one.

Example :

Input : [1 2 3 1 1]
Output : 1 
1 occurs 3 times which is more than 5/3 times. 
*/

int Solution::repeatedNumber(const vector<int> &A) {
    
    int n=A.size();
    if(n==0){
        return -1;
    }
    if(n<=2){
        return A[0];
    }
    int n3=n/3;
    int c1=0,c2=0,f=0,s=0;
    for(int i=0;i<n;i++){
        if(A[i]==f){
            c1++;
        }else if(A[i]==s){
            c2++;
        }else if(c1==0){
            c1=1;
            f=A[i];
        }else if(c2==0){
            c2=1;
            s=A[i];
        }else{
            c1--;
            c2--;
        }
    }
    c1=0;
    c2=0;
    for(int i=0;i<n;i++){
        if(f==A[i]){
            c1++;
        }else if(s==A[i]){
            c2++;
        }
    }
    if(c1>n3){
        return f;
    }else if(c2>n3){
        return s;
    }
    return -1;
}
