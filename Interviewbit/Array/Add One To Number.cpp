/*
Given a non-negative number represented as an array of digits,

add 1 to the number ( increment the number represented by the digits ).

The digits are stored such that the most significant digit is at the head of the list.

Example:

If the vector has [1, 2, 3]

the returned vector should be [1, 2, 4]

as 123 + 1 = 124.
*/

vector<int> Solution::plusOne(vector<int> &A) {
    vector<int> B;
    int sum=A[A.size()-1]+1;
    int rem=sum/10;
    sum%=10;
    B.push_back(sum);
    int flag=0;
    for(int i=0;i<A.size();i++){
        if(A[i]==0){
            A[i]=-1;
        }else{
            break;
        }
    }
    for(int i=A.size()-2;i>=0;i--){
        if(A[i]==-1){
            break;
        }
        if(rem==0){
            B.push_back(A[i]);
        }else{
            sum=rem+A[i];
            rem=sum/10;
            sum%=10;
            B.push_back(sum);
        }
    }
    if(rem!=0){
        B.push_back(rem);
    }
   
    for(int i=0;i<(B.size())/2;i++){
        swap(B[i],B[B.size()-i]);
    }
    return B;
}
